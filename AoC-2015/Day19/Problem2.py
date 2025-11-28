# This Problem can be reduced to finding min number of stpes to generate a string
# Given Context Free Grammar(CFG) in it Chomesky Normal Form(CNF)
# We implemented this in our assignment so we used

# ALGORITHM
# 1. Convert the given input to CFG
# 2. Convert the CFG to CNF (there is a standard algorithm for that)
# 3. Use CYK algorithm with a small modification to get the min_steps

from collections import defaultdict, deque
import math

INF = 10**18

def tokenize_molecule(mol: str):
    """
    Split string like 'CRnCaSiRnBSi...' into element tokens:
    ['C', 'Rn', 'Ca', 'Si', 'Rn', 'B', 'Si', ...]
    """
    tokens = []
    i = 0
    while i < len(mol):
        assert mol[i].isupper()
        j = i + 1
        while j < len(mol) and mol[j].islower():
            j += 1
        tokens.append(mol[i:j])
        i = j
    return tokens

class Grammar:
    def __init__(self):
        self.nt_index = {}     # nonterminal name -> id
        self.nt_names = []     # id -> name
        self.terminal_index = {}  # terminal string -> id (only for clarity)
        self.term_names = []
        
        self.lex_rules = defaultdict(list)   # terminal -> list of (A, cost)
        self.binary_rules = []              # list of (A, B, C, cost)
        self.unit_rules = defaultdict(list) # B -> list of (A, cost)
        
        self.start = self.get_nt("S")       # start symbol corresponding to 'e'
    
    def get_nt(self, name: str) -> int:
        if name not in self.nt_index:
            self.nt_index[name] = len(self.nt_names)
            self.nt_names.append(name)
        return self.nt_index[name]
    
    def get_term(self, sym: str) -> int:
        if sym not in self.terminal_index:
            self.terminal_index[sym] = len(self.term_names)
            self.term_names.append(sym)
        return self.terminal_index[sym]
    
    def add_lex_rule(self, A_name: str, term_sym: str, cost: int = 0):
        """A -> term_sym (terminal)"""
        A = self.get_nt(A_name)
        t = self.get_term(term_sym)
        self.lex_rules[t].append((A, cost))
    
    def add_binary_rule(self, A_name: str, B_name: str, C_name: str, cost: int = 0):
        """A -> B C"""
        A = self.get_nt(A_name)
        B = self.get_nt(B_name)
        C = self.get_nt(C_name)
        self.binary_rules.append((A, B, C, cost))
    
    def add_unit_rule(self, A_name: str, B_name: str, cost: int = 0):
        """A -> B"""
        A = self.get_nt(A_name)
        B = self.get_nt(B_name)
        self.unit_rules[B].append((A, cost))

def build_grammar_from_replacements(replacements, target_molecule):
    """
    replacements: list of (lhs_str, rhs_str) as in AoC input.
      Example: "H", "HO"  for 'H => HO'
    target_molecule: the *string* of the final molecule (to collect needed tokens).
    """
    G = Grammar()
    
    # Collect all element tokens that appear anywhere
    elements = set()
    for lhs, rhs in replacements:
        if lhs != "e":
            elements.add(lhs)
        for tok in tokenize_molecule(rhs):
            elements.add(tok)
    for tok in tokenize_molecule(target_molecule):
        elements.add(tok)
    
    # For each element token X, we create:
    # Nonterminal "N_X" and lexical rule N_X -> X with cost 0
    for el in elements:
        G.add_lex_rule(f"N_{el}", el, cost=0)
    
    # Now convert each replacement rule into CNF-style rules with cost = 1 per replacement
    new_nt_counter = 0
    
    def fresh_aux_nt():
        nonlocal new_nt_counter
        name = f"Aux_{new_nt_counter}"
        new_nt_counter += 1
        return name
    
    for lhs, rhs in replacements:
        # LHS nonterminal: S for 'e', else N_<lhs>
        if lhs == "e":
            A_name = "S"
        else:
            A_name = f"N_{lhs}"
        
        rhs_tokens = tokenize_molecule(rhs)   # list of element symbols
        if not rhs_tokens:
            continue  # shouldn't really happen in AoC
        
        # Convert RHS elements to their nonterminal names
        rhs_nt = [f"N_{tok}" for tok in rhs_tokens]
        k = len(rhs_nt)
        
        if k == 1:
            # A -> B  (one-symbol RHS)
            # This corresponds to one replacement step; treat as a unit rule with cost=1
            G.add_unit_rule(A_name, rhs_nt[0], cost=1)
        elif k == 2:
            # A -> B C  (binary rule)
            # This single production corresponds to one replacement step
            G.add_binary_rule(A_name, rhs_nt[0], rhs_nt[1], cost=1)
        else:
            # A -> B1 B2 ... Bk, k >= 3
            # We need to break into CNF:
            #   A -> B1 Y1   (cost = 1)
            #   Y1 -> B2 Y2  (cost = 0)
            #   ...
            #   Y_{k-2} -> B_{k-1} B_k (cost = 0)
            first = rhs_nt[0]
            rest = rhs_nt[1:]
            
            Y_prev = fresh_aux_nt()
            G.add_binary_rule(A_name, first, Y_prev, cost=1)  # top rule with cost = 1
            
            for i in range(len(rest) - 2):
                # Y_i -> B_{i+1} Y_{i+1}
                B_i = rest[i]
                Y_next = fresh_aux_nt()
                G.add_binary_rule(Y_prev, B_i, Y_next, cost=0)
                Y_prev = Y_next
            
            # Last one: Y_{k-2} -> B_{k-1} B_k
            G.add_binary_rule(Y_prev, rest[-2], rest[-1], cost=0)
    
    return G

def min_steps_via_cyk(replacements, target_molecule):
    """
    Return minimal number of replacement steps from 'e' to target_molecule,
    using a CYK-like DP on a weighted CFG derived from `replacements`.
    
    replacements: list of (lhs, rhs) strings from AoC input.
    target_molecule: target molecule string.
    """
    tokens = tokenize_molecule(target_molecule)
    n = len(tokens)
    if n == 0:
        return 0  # empty target: trivial
    
    G = build_grammar_from_replacements(replacements, target_molecule)
    start_nt = G.start
    
    # Re-index grammar data structures for speed
    # Map (B, C) -> [(A, cost)]
    binary_index = defaultdict(list)
    for A, B, C, c in G.binary_rules:
        binary_index[(B, C)].append((A, c))
    
    # unit_rules: already as B -> [(A, cost)]
    
    # dp[i][j] = dict { nonterminal_id: min_cost }
    # We'll store as a 2D list of dicts.
    dp = [[{} for _ in range(n)] for __ in range(n)]
    
    # 1. Initialize length-1 spans with lexical rules
    #    For each token t at position i, we apply A -> t rules (cost 0),
    #    then close under unit rules.
    term_to_id = {sym: tid for sym, tid in G.terminal_index.items()}
    
    # Invert terminal_index to use tokens directly
    term_id_by_sym = {sym: tid for sym, tid in G.terminal_index.items()}
    
    for i, tok in enumerate(tokens):
        span = dp[i][i]
        # lexical rules
        if tok not in term_id_by_sym:
            continue  # no grammar symbol; impossible
        tid = term_id_by_sym[tok]
        for A, c_lex in G.lex_rules.get(tid, []):
            old = span.get(A, INF)
            new = min(old, c_lex)
            if new < old:
                span[A] = new
        
        # unit closure: propagate A -> B with costs
        queue = deque(span.keys())
        while queue:
            B = queue.popleft()
            base_cost = span[B]
            for A, c_unit in G.unit_rules.get(B, []):
                cand = base_cost + c_unit
                old = span.get(A, INF)
                if cand < old:
                    span[A] = cand
                    queue.append(A)
    
    # 2. Spans of length >= 2
    for length in range(2, n + 1):
        for i in range(0, n - length + 1):
            j = i + length - 1
            span = dp[i][j]
            
            # Consider all splits (i..k, k+1..j)
            for k in range(i, j):
                left = dp[i][k]
                right = dp[k + 1][j]
                if not left or not right:
                    continue
                # Try all B in left, C in right
                for B, costB in left.items():
                    for C, costC in right.items():
                        for A, c_prod in binary_index.get((B, C), []):
                            cand = costB + costC + c_prod
                            old = span.get(A, INF)
                            if cand < old:
                                span[A] = cand
            
            # Unit closure on this span
            if span:
                queue = deque(span.keys())
                while queue:
                    B = queue.popleft()
                    base_cost = span[B]
                    for A, c_unit in G.unit_rules.get(B, []):
                        cand = base_cost + c_unit
                        old = span.get(A, INF)
                        if cand < old:
                            span[A] = cand
                            queue.append(A)
    
    # Answer: min cost to derive whole string from start nonterminal S
    result = dp[0][n - 1].get(start_nt, INF)
    return None if result == INF else result

if __name__ == "__main__":
    formula = ""
    replacements = []

    with open("Day19/input.txt") as f:
        for line in f:
            if "=>" not in line:
                formula += line.strip()
            else:
                a, b = line.split("=>", 1)
                a, b = a.strip(), b.strip()
                if a in replacements:
                    replacements[a].append(b)
                else:
                    replacements.append((a, b))
    
    
    steps = min_steps_via_cyk(replacements, formula)
    print("Min steps:", steps)