%zebra
hasBlackStripes(animal1).
hasHair(animal1).
givesMilk(animal1).
hasHooves(animal1).

%giraffe
hasDarkSpots(animal2).
hasLongNeck(animal2).
hasHair(animal2).
givesMilk(animal2).
hasHooves(animal2).

%tiger
hasTawnyColour(animal3).
hasBlackStripes(animal3).
hasHair(animal3).
givesMilk(animal3).
hasPointedTeeth(animal3).
hasClaws(animal3).
hasForwardEyes(animal3).

%cheetah
hasHair(animal4).
givesMilk(animal4).
eatsMeat(animal4).
hasTawnyColour(animal4).
hasDarkSpots(animal4).

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
