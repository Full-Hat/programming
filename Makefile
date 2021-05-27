lab: account.cpp accountSet.cpp interface.cpp main.cpp menu.cpp  
	g++ -o lab7 account.cpp accountSet.cpp interface.cpp main.cpp menu.cpp
test: account.cpp accountSet.cpp interface.cpp test.cpp menu.cpp  
	g++ -o lab7_test account.cpp accountSet.cpp interface.cpp test.cpp menu.cpp -fprofile-arcs -ftest-coverage -lgcov -g

