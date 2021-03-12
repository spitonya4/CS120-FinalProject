# This file will scrap all the pokemon lists and send the pokemon
# to the C++ file

import random
import requests
import subprocess
import os
from bs4 import BeautifulSoup


def main():

    # Open up a file and write to it the pokemon
    fire = open('firePokemon.txt', 'w')
    firePokemon(fire)
    fire.close()

    grass = open('grassPokemon.txt', 'w')
    grassPokemon(grass)
    grass.close()

    water = open('waterPokemon.txt', 'w')
    waterPokemon(water)
    water.close()

    # Open the files to get a pokemon
    fire = open('firePokemon.txt', 'r')
    grass = open('grassPokemon.txt', 'r')
    water = open('waterPokemon.txt', 'r')
    # Call the line counter function
    firePoke = lineCounter(fire)
    randFire = random.randint(0, firePoke)
    fire.close()

    # Call the line counter function
    grassPoke = lineCounter(grass)
    randGrass = random.randint(0, grassPoke)
    grass.close()

    # Call the line counter function
    waterPoke = lineCounter(water)
    randWater = random.randint(0, waterPoke)
    water.close()

    fire = open('firePokemon.txt', 'r')
    grass = open('grassPokemon.txt', 'r')
    water = open('waterPokemon.txt', 'r')


    fireLines = fire.readlines()
    fireName = fireLines[randFire - 1].strip()


    grassLines = grass.readlines()
    grassName = grassLines[randGrass - 1].strip()

    waterLines = water.readlines()
    waterName = waterLines[randWater - 1].strip()

    fire.close()
    water.close()
    grass.close()

    # Send the names to the C++ file
    # try:
    #     subprocess.call('gcc -std=c++1y -c main.cpp', stdin=None, stdout=None, stderr=None, shell=True)
    # except subprocess.CalledProcessError as e:
    #     print("<p>", e.output, "</p>")
    #     raise SystemExit
    #
    # # Create a string to send the names to
    # sendString = 'g++ -o ./a.out main.o ' + fireName + ' ' + grassName + ' ' + waterName
    print(fireName)
    print(grassName)
    print(waterName)
    # sendString = 'g++ -o ./main.o ' + fireName + ' ' + grassName + ' ' + waterName
    sendString = './a.out ' + fireName + ' ' + grassName + ' ' + waterName
    # subprocess.call(sendString, shell=True, stdout=None, stdin=None)
    p = subprocess.call('gcc -std=c++1y -c main.cpp Pokemon.cpp Trainer.cpp FireType.cpp GrassType.cpp Pokeball.cpp WaterType.cpp',
                        stdin=None, stdout=None, stderr=None, shell=True)
    if p != 0:
        print("C++ compile errors")
    else:
        subprocess.call('g++ main.o Pokemon.o Trainer.o FireType.o GrassType.o PokeBall.o WaterType.o',
                        stdin=None, stdout=None, stderr=None, shell=True)
        print(subprocess.Popen('./a.out', shell=True, stdout=subprocess.PIPE, stdin=subprocess.PIPE, universal_newlines=True).stdout.read().rstrip())


def firePokemon(fire):
    # Get the url wanted for the fire type
    url = 'https://bulbapedia.bulbagarden.net/wiki/Fire_(type)'

    r = requests.get(url)

    soup = BeautifulSoup(r.text, 'html.parser')

    tables = soup.findAll('table', class_="roundy")

    fireTable = tables[1]

    repeat = ""

    for firePokemon in fireTable.findAll('th'):
        for img in firePokemon.findAll('img'):
            pokemonName = img.get('alt')
            # Make sure no pokemon names are repeated
            if (repeat != pokemonName):
                repeat = pokemonName
                fire.write(pokemonName + '\n')



def grassPokemon(grass):
    # Get the url wanted for the grass type
    url = 'https://bulbapedia.bulbagarden.net/wiki/Grass_(type)'

    r = requests.get(url)

    soup = BeautifulSoup(r.text, 'html.parser')

    tables = soup.findAll('table', class_="roundy")

    grassTable = tables[1]

    repeat = ""

    for grassPokemon in grassTable.findAll('th'):
        for img in grassPokemon.findAll('img'):
            pokemonName = img.get('alt')
            # Make sure no pokemon names are repeated
            if (repeat != pokemonName):
                repeat = pokemonName
                grass.write(pokemonName + '\n')


def waterPokemon(water):
    # Get the url wanted for the water type
    url = 'https://bulbapedia.bulbagarden.net/wiki/Water_(type)'

    r = requests.get(url)

    soup = BeautifulSoup(r.text, 'html.parser')

    tables = soup.findAll('table', class_="roundy")

    waterTable = tables[1]

    repeat = ""

    for waterPokemon in waterTable.findAll('th'):
        for img in waterPokemon.findAll('img'):
            pokemonName = img.get('alt')
            # Make sure no pokemon names are repeated
            if (repeat != pokemonName):
                repeat = pokemonName
                water.write(pokemonName + '\n')


def getPokemon(fire, grass, water):

    # Call the line counter function
    firePoke = lineCounter(fire)
    randFire = random.randint(1, firePoke)
    print(randFire)

    # for x in range(1, randFire):
    print(fire.readline())

    # fireName = getPokeName(randFire, fire)
    # print(fireName)



def lineCounter(file):
    lines = 0
    for x in file:
        lines += 1
    return lines

def getPokeName(pokeNumber, file):
    counter = 0
    for x in range(1, pokeNumber):
        name = file.readLine().strip()
        if not name:
            break

    return name

main()