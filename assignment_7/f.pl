
zebra(zeb1).
zebra(zeb2).
cheetah(cheet1).
cheetah(cheet2).
tiger(tig1).
tiger(tig2).

mammal(X):- hasHair(X).
mammal(X):- givesMilk(X).
carnivore(X):- eatsMeat(X).
carnivore(X):- hasPointedTeeth(X), hasClaws(X), hasForwardEyes(X).
ungulate(X):- mammal(X), hasHooves(X).
ungulate(X):- mammal(X), chewsCud(X).
cheetah(X):- mammal(X), carnivore(X), hasTawnyColour(X), hasDarkSpots(X).
tiger(X):- hasTawnyColour(X), hasBlackStripes(X), mammal(X), carnivore(X).
giraffe(X):- hasDarkSpots(X), hasLongNeck(X), ungulate(X).
zebra(X):- hasBlackStripes(X), ungulate(X).

