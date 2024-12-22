import random
import matplotlib.pyplot as plt
from math import comb

# https://github.com/mirolaukka/Birthday-Paradox/blob/main/birthday_paradox.py
def _probability_simulation(num_people):
    """Calculate the probability of at least two people sharing a birthday in a group."""
    num_simulations = 100000
    success_count = 0

    for _ in range(num_simulations):
        birthdays = set(random.randint(1, 365) for _ in range(num_people))
        if len(birthdays) != num_people:
            success_count += 1

    probability = success_count / num_simulations
    
    return probability

def birthday_paradox_probability_simulation():
    indices=[]
    probabilities=[]

    for i in range(2,25):
        indices.append(i)
        
        probability = _probability_simulation(i)
        probabilities.append(probability)
    
    plt.plot(indices, probabilities, '-D', label='')

    plt.yticks([x * 0.1 for x in range(0, 10)])

    plt.xlabel('People in the room')
    plt.ylabel('Probability of two people having the same birthday')

    plt.title('Birthday Paradox')

    plt.show()

# 1 - ((364/365) ^ nC2)
def _probability(num_people):
    number_of_possible_selections = comb(num_people, 2)
    return 1 - pow(364/365, number_of_possible_selections)

def birthday_paradox_probability_mathematical():
    indices=[]
    probabilities=[]

    for i in range(2,100):
        indices.append(i)
        
        probability = _probability(i)
        probabilities.append(probability)

    markers_on = [2, 23, 70]
    plt.plot(indices, probabilities, '-D', markevery=markers_on, label='')

    plt.yticks([x * 0.1 for x in range(0, 10)])

    plt.xlabel('People in the room')
    plt.ylabel('Probability of two people having the same birthday')

    plt.title('Birthday Paradox')

    plt.show()


def main():
    # birthday_paradox_probability_mathematical()
    birthday_paradox_probability_simulation()
    

if __name__ == "__main__":
    main()

