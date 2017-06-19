# qpaper-generator
Program to generate question papers from a question bank(database-.db file). This is program is meant to provide questions randomly as a suggestion and thus it avoids biases and preference caused when you select questions yourself from a question bank. 

# Instructions for creating the database:
1. The database should have the following columns in proper order QID(INTEGER), Difficulty(TEXT), Question(TEXT) and Marks(INTEGER). 
2. You can use DB Browser for Sqlite, which will be even easier to enter data manually in a database. 
3. There are three levels of difficulty, i.e., E(Easy)/M(Medium)/H(Hard).
4. The program wont run(or may give wrong results) if the database isn't in a proper order.
5. A sample.db has been provided. 

# Output
The output will be generated as a .txt file- qpaper.txt, so that if you wish to edit the questions or wish to add more according to your wish you can make changes freely.
Copy the contents of the text file or duplicate it into another folder as new data will be fed into it once the program re-runs. 

# Sqlite3 
Sqlite libraries used.
*sqlite.h
*sqliteext.h

and sqlite.c

# C++ 11
C++11 compiler also used. 

