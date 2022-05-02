Buy.o: Buy.cpp Buy.h
	g++  -pedantic-errors -std=c++11 -c $<
Sell.o: Sell.cpp Sell.h
	g++  -pedantic-errors -std=c++11 -c $<
Rank.o: Rank.cpp Rank.h
	g++  -pedantic-errors -std=c++11 -c $<
Checkout.o: Checkout.cpp Checkout.h
	g++  -pedantic-errors -std=c++11 -c $<
Main.o: Main.cpp Buy.h Sell.h Rank.h Checkout.h
	g++  -pedantic-errors -std=c++11 -c $<
Game: Buy.o Sell.o Rank.o Checkout.o Main.o
	g++  -pedantic-errors -std=c++11 Buy.o Sell.o Rank.o Checkout.o Main.o -o Game
clean:
	rm -f *.o Game
