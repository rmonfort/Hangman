#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <cctype>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::set;

// Randomly returns a word in a preset word list
string select_word()
{
	string word_list[115] = {
		"acres",
		"adult",
		"advice",
		"attempt",
		"border",
		"breeze",
		"brick",
		"calm",
		"canal",
		"cast",
		"chose",
		"claws",
		"coach",
		"contrast",
		"cookies",
		"customs",
		"damage",
		"Danny",
		"deeply",
		"depth",
		"discussion",
		"doll",
		"donkey",
		"Egypt",
		"essential",
		"exchange",
		"exist",
		"explanation",
		"facing",
		"film",
		"finest",
		"fireplace",
		"floating",
		"folks",
		"fort",
		"garage",
		"grabbed",
		"grandmother",
		"habit",
		"happily",
		"Harry",
		"heading",
		"hunter",
		"Illinois",
		"image",
		"independent",
		"instant",
		"January",
		"kids",
		"label",
		"Lee",
		"lungs",
		"manufacturing",
		"mathematics",
		"melted",
		"memory",
		"mill",
		"mission",
		"monkey",
		"Mount",
		"mysterious",
		"neighborhood",
		"nuts",
		"occasionally",
		"official",
		"ourselves",
		"palace",
		"plates",
		"poetry",
		"policeman",
		"positive",
		"possibly",
		"practical",
		"pride",
		"promised",
		"recall",
		"relationship",
		"remarkable",
		"require",
		"rhyme",
		"rocky",
		"rubbed",
		"rush",
		"sale",
		"satellites",
		"satisfied",
		"scared",
		"shake",
		"shaking",
		"shallow",
		"shout",
		"silly",
		"simplest",
		"slight",
		"slip",
		"slope",
		"soap",
		"solar",
		"species",
		"spin",
		"stiff",
		"swung",
		"tales",
		"thumb",
		"tobacco",
		"toy",
		"trap",
		"treated",
		"tune",
		"university",
		"vapor",
		"vessels",
		"wealth",
		"wolf",
		"zoo",
	};

	// Random generator engine from a time based seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);

	// Generates a random index within the range the size of the array and returns the word
	uniform_int_distribution<int> distribution(0, 114);
	int index = distribution(generator);
	return word_list[index];
}

// Returns true if answer is yes
bool isYes(const string& answer)
{
	return answer == "y" || answer == "Y" || answer == "yes" || answer == "Yes";
}

// Returns false is answer is no
bool isNo(const string& answer)
{
	return answer == "n" || answer == "N" || answer == "no" || answer == "No";
}

// Draws gallows based on status
void print_gallows(const int& status = 0)
{
	switch (status)
	{
	case 0:
		cout << "\n" << endl
			<< "   +----+  " << endl
			<< "   |    |  " << endl
			<< "   |       " << endl
			<< "   |       " << endl
			<< "   |       " << endl
			<< "   |       " << endl
			<< "  =============\n" << endl;
		break;
	case 1:
		cout << "\n" << endl
			<< "   +----+  " << endl
			<< "   |    |  " << endl
			<< "   |    O  " << endl
			<< "   |       " << endl
			<< "   |       " << endl
			<< "   |       " << endl
			<< "  =============\n" << endl;
		break;
	case 2:
		cout << "\n" << endl
			<< "   +----+  " << endl
			<< "   |    |  " << endl
			<< "   |    O  " << endl
			<< "   |    |  " << endl
			<< "   |       " << endl
			<< "   |       " << endl
			<< "  =============\n" << endl;
		break;
	case 3:
		cout << "\n" << endl
			<< "   +----+  " << endl
			<< "   |    |  " << endl
			<< "   |    O  " << endl
			<< "   |   /|  " << endl
			<< "   |       " << endl
			<< "   |       " << endl
			<< "  =============\n" << endl;
		break;
	case 4:
		cout << "\n" << endl
			<< "   +----+  " << endl
			<< "   |    |  " << endl
			<< "   |    O  " << endl
			<< "   |   /|\\ " << endl
			<< "   |       " << endl
			<< "   |       " << endl
			<< "  =============\n" << endl;
		break;
	case 5:
		cout << "\n" << endl
			<< "   +----+  " << endl
			<< "   |    |  " << endl
			<< "   |    O  " << endl
			<< "   |   /|\\ " << endl
			<< "   |   /   " << endl
			<< "   |       " << endl
			<< "  =============\n" << endl;
		break;
	case 6:
		cout << "\n" << endl
			<< "   +----+  " << endl
			<< "   |    |  " << endl
			<< "   |    O  " << endl
			<< "   |   /|\\ " << endl
			<< "   |   / \\" << endl
			<< "   |       " << endl
			<< "  =============\n" << endl;
		break;
	default:
		break;
	}
}

int main(int argc, char *argv[])
{
	int play_again = 0;
	do
	{
		/*
		* Setup
		*/

		string secret_word = select_word(); // Randomly generates secret word
		string word_puzzle(secret_word.length(), '*'); //Build word_puzzle initially with astericks
		int bad_guesses = 0; // Counter for the number of bad guesses
		string alphabet = "abcdefghijklmnopqrstuvwxyz"; // Now I know my ABCs....
		set<char> letters(alphabet.begin(), alphabet.end()); // Populate set with alphabet to keep track of what letters were used

		/*
		* Game Start
		*/

		// Print gallows, word puzzle, and letters left
		print_gallows();
		cout << "\t" << word_puzzle << "\n" << endl;
		for (auto& c : letters)
		{
			cout << c << " ";
		}
		cout << "\n" << endl;

		int game_over = 0; // Game over flag
		do
		{
			// Ask for guesses
			cout << "Please guess a letter: ";
			char guess;
			cin >> guess;


			// Check if the guess is an actual letter
			while (!isalpha(guess))
			{
				cout << "That doesn't look like a letter to me... Please try again: ";
				cin >> guess;
			}

			guess = tolower(guess); // Set letter to lowercase to avoid comparison issues

			// Check if letter has been chosen before
			if (letters.erase(guess))
			{
				// Check if letter is found in string
				if (secret_word.find(guess) != string::npos)
				{
					// If found replace asterick with letter in word puzzle
					cout << "Good guess!" << endl;
					for (size_t i = 0; i < secret_word.length(); i++)
					{
						if (secret_word[i] == guess)
						{
							word_puzzle[i] = guess;
						}
					}
					print_gallows(bad_guesses);
					cout << "\t" << word_puzzle << "\n" << endl;
					for (auto& c : letters)
					{
						cout << c << " ";
					}
					cout << "\n" << endl;

					// Check if user has won
					if (secret_word == word_puzzle)
					{
						cout << "You've escaped the gallows! You win!" << endl;
						game_over = 1;
					}
				}
				else
				{
					// Otherwise increment bad guess count
					cout << "Sorry, that was a bad guess..." << endl;
					bad_guesses++;
					print_gallows(bad_guesses);
					cout << "\t" << word_puzzle << "\n" << endl;
					for (auto& c : letters)
					{
						cout << c << " ";
					}
					cout << "\n" << endl;

					//Check if user has lost
					if (bad_guesses == 6)
					{
						cout << "You've been hung! You lose!" << endl;
						cout << "The word was " << secret_word << "." << endl;
						game_over = 1;
					}
				}
			}
			else
			{
				// If letter has been used before, return to beginning of loop
				cout << "This letter was already chosen previously. Please try again." << endl;
			}

		} while (!game_over);

		/*
		* Continue option
		*/

		// Ask user if they want to play again
		do
		{
			cout << "Would you like to play again (y or n)? ";
			string answer;
			cin >> answer;

			if (isYes(answer))
			{
				play_again = 1;
				break;
			}
			else if (isNo(answer))
			{
				play_again = 0;
				break;
			}
			else
			{
				// Continue looping if given an unrecoginized input
				cout << "I'm sorry. I couldn't understand your input. Please try again." << endl;
			}
		} while (true);
	} while (play_again);

	cout << "Thanks for playing!" << endl;

	return 0;
}