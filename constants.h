/* 
 * File:   constants.h
 * Author: U140172
 *
 * Created on 25 de mayo de 2017, 13:33
 */

#ifndef CONSTANTS_H
#define	CONSTANTS_H

#define MAXLENGTH 150
#define LENGTH15 15
#define MAXLENGTH3 3

#define STRINGDEFAULT "Default"
#define STRINGROOT "root"
#define STRINGLEFT "left"
#define STRINGRIGHT "right"

#define TRUE 1
#define FALSE 0

//Colors
#define COLOR_RED   "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_RESET "\x1b[0m"

//Strings
#define STR_WLC "Welcome to the Overlord, the making decisions program.\nPress enter to continue\n"
#define STR_SGST "The Overlord say: %s. \n"
#define STR_ANSY "If the answerd to the question *%s* is: Yes \n"
#define STR_ANSN "If the answerd to the question *%s* is: No \n"
#define STR_THNK "Thanks for use Overlord"
#define STR_ERR_INPUT "Error: Not valid input\n"
#define STR_EMPTY_TREE "Error: This tree is empty"
#define STR_YES "yes"
#define STR_NO "no"

//Menu
#define STR_ENTOP "Enter an option: \n"
#define STR_EX1AUTO "\t 1 - Run automaticaly the food tree \n"
#define STR_EX2AUTO "\t 2 - Run automaticaly the films tree \n"
#define STR_EX1MN "\t 3 - Run manually the food tree \n"
#define STR_EX2MN "\t 4 - Run manually the films tree \n"
#define STR_LDTRE "\t 5 - Load a saved tree \n"
#define STR_EXIT "\t 0 - Exit of Overlord \n"
#define STR_NTVA "Not valid option \n"
#define STR_JUMP "\n\n"

//Options
#define MTAUTO 1
#define FTAUTO 2
#define MTMANU 3
#define FTMANU 4
#define LDTRIF 5
#define EXITOV 0

//TREE1
#define TREE1_1 "Are you vegetarian?"
#define TREE1_2 "Do you like tomatoes?"
#define TREE1_3 "Do you like olive oil?"
#define TREE1_4 "Do you like beef?"
#define TREE1_5 "Do you like potatoes?"
#define TREE1_6 "Do you like spicy food?"
#define TREE1_8 "I suggest bread & tomatoes"
#define TREE1_9 "I suggest tomato soup"
#define TREE1_10 "I suggest green salad"
#define TREE1_11 "I suggest grilled beef & french fries"
#define TREE1_12 "I suggest grilled beef & tomato salad"
#define TREE1_13 "I suggest chicken tikka"
#define TREE1_14 "I suggest fried chicken"

//TREE2
#define TREE2_1 "Is your age <= 16?"
#define TREE2_2 "Is your age > 16 and <= 50 ?"
#define TREE2_3 "Do you like suspense?"
#define TREE2_4 "Do you like musicals?"
#define TREE2_5 "Do you like romance?"
#define TREE2_6 "Do you like thrillers?"
#define TREE2_8 "Do you like superheroes?"
#define TREE2_9 "Watch Frozen"
#define TREE2_10 "Watch Spiderman"
#define TREE2_11 "Watch Shakespeare in Love"
#define TREE2_12 "Watch Fast and Furious 100"
#define TREE2_13 "Watch the Davinci Code"
#define TREE2_14 "Watch La La Land"
#define TREE2_15 "Watch Back to Future"



#endif	/* CONSTANTS_H */

