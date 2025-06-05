# Self-Evaluation

## Name(s): Farheen Ibrahim and Zeba Khan

Out of 25 points. Use output.txt created using 
`./create-output.sh > output.txt 2>&1` for guidance.

Complete all questions with "Q:"

Q: Does the program compile and run to completion: Yes/No  YES

- If the program does not compile or gives a segmentation error when run, 
the maximum possible grade is 50%. No need to continue with the rest of self-evaluation

Q: All public functions have been implemented: YES all fully implemented 

- -2 for each functionality not implemented

For each command, state Full, Partial or None to indicate 
if it has been fully, partially or not implemented at all.
Explain any partial implementations.

Inventory: TODO(student)
History: TODO(student)
Borrow: TODO(student)
Return: TODO(student)


Q: -1 for each compilation warning, min -3: 0 All Complies 

- Check under *1. Compiles without warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-tidy warning, min -3: 0 No clang-tidy warnings 

- Check under *3. clang-tidy warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-format warning, min -3: 0 No clang-format errors

- Check under *4. clang-format does not find any formatting issues*


Q: -2 for any detected memory leak: 0 No memory leaks

- Check under *5. No memory leaks using g++*
- Check under *6. No memory leaks using valgrind*

Q: Do the tests sufficiently test the code: 0 All code tests 

- -1 for each large block of code not executed
- -2 for each function that is never called when testing
- Check under *7. Tests have full code coverage* paying attention to *The lines below were never executed*

Q: Are all functions in .h and .cpp file documents (min -3): All functions documented

- -1 for each function not documented

## Location of error message or functionality

State the file and function where the information can be found

invalid command code: CommandFactory.cpp → createCommand()

invalid movie type: MovieFactory.cpp → createMovie()

invalid customer ID: StoreManager.cpp → processCommand() (calls CustomerManager::getCustomer())

invalid movie: StoreManager.cpp → handleBorrow() and handleReturn()
(errors triggered in MovieHashTable::retrieve() if movie not found)

factory classes: MovieFactory and CommandFactory both use self-registration for extensibility

hashtable: movie_hashtable files used to display the genre of the movie 

container used for comedy movies: std::vector<Movie*> inside MovieHashTable for genre 'F'

function for sorting comedy movies: Comedy::operator<() and sorting done in MovieHashTable::printGenre('F')

function where comedy movies are sorted: MovieHashTable::printGenre() sorts std::vector<Movie*> using std::sort()

functions called when retrieving a comedy movie based on title and year: Comedy::create() → for building temp movie
MovieHashTable::retrieve() → for retrieval

functions called for retrieving and printing customer history: StoreManager::handleHistory() →
calls Customer::printHistory()

container used for customer history: std::vector<Command*> in each Customer object

functions called when borrowing a movie: StoreManager::handleBorrow() →
calls Customer::addHistory() and Movie::decreaseStock()

explain borrowing a movie that does not exist: MovieHashTable::retrieve() returns false →
error printed in StoreManager::handleBorrow()

explain borrowing a movie that has 0 stock: Movie::decreaseStock() returns false if stock is 0 →
error printed in handleBorrow()

explain returning a movie that customer has not checked out: Customer::hasBorrowed(movie) returns false →
error printed in handleReturn()

any static_cast or dynamic_cast used: Yes – dynamic_cast<Classic*>(movie) in command handlers to check genre-specific info (e.g., Classic month & actor)

## Bonus +5

Are there multiple files, of the form runit-without-XXX, where the same set of files will compile and run excluding some of the commands or genres? YES

Q: Total points: ADD_ALL_POINTS (max 25 (+ 5 Bonus)) TOTAL: 30 Points 