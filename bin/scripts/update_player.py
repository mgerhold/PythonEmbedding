from game import Player

def update(p : Player, textOutput : bool):
    if textOutput:
        print("[Python]", p.getX())
    p.move(1, 0)
    if textOutput:
        print("[Python]", p.getX())    