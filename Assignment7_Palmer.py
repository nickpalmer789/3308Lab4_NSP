import random

#The main function
def main():
	playAgain = True
	while playAgain == True:
		#Get input from the user
		response = raw_input("Do you want to play a game? (y) or (n): ")
		
		#Check the user's input
		if response == "y":
			#Play the game
			playMadLibs()
		else:
			#Exit the game
			playAgain = False;
			print "good bye"
		

def playMadLibs():
	#The templates with %s wherever a string needs to be subbed in
	templates = ["Be kind to your %s-footed %s, or a duck may be somebody's %s.", "It was the %s of %s, it was the %s of %s.", "%s? I don't have to show you any %s %s!", "My %s always said %s was like a box of %s. You never know what you're gonna get.", "One %s, I %s a %s in my pajamas. How he got in my pajamas, I don't know."]
	
	#Choose a random template to play
	choice = random.randrange(0, 5)
	
	#Play the different templates
	if choice == 0:
		#Get the inputs
		noun1 = getNoun()
		pluralNoun = getPluralNoun()
		noun2 = getNoun()
		print(templates[choice]%(noun1, pluralNoun, noun2))
	elif choice == 1:
		#Get the inputs
		adjective1 = getAdjective()
		noun1 = getNoun()
		adjective2 = getAdjective()
		noun2 = getNoun()
		print(templates[choice]%(adjective1, noun1, adjective2, noun2))
	elif choice == 2:
		#Get the inputs
		pluralNoun1 = getPluralNoun()
		adjective = getAdjective()
		pluralNoun2 = getPluralNoun()
		print(templates[choice]%(pluralNoun1, adjective, pluralNoun2))
	elif choice == 3:
		#Get the inputs
		relative = getRelative()
		noun1 = getNoun()
		noun2 = getNoun()
		print(templates[choice]%(relative, noun1, noun2))
	elif choice == 4:
		#Get the inputs
		timeOfDay = getTimeOfDay()
		verb = getVerb()
		noun = getNoun()
		print(templates[choice]%(timeOfDay, verb, noun))
		

#Functions to get the various parts of speech
def getNoun():
	return raw_input("Enter a noun: ")

def getPluralNoun():
	return raw_input("Enter a plural noun: ")

def getAdjective():
	return raw_input("Enter an adjective: ")

def getTimeOfDay():
	return raw_input("Enter a time of day: ")

def getRelative():
	return raw_input("Enter a relative: ")

def getVerb(): 
	return raw_input("Enter a verb: ")

#Run the main function when the script starts
if __name__ == "__main__":
	main()
