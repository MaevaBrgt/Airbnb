airbnb: airbnb.c fonctions.c fonctions.h
	gcc -o airbnb airbnb.c -lm && ./airbnb

clean:
	rm airbnb

run :
	./airbnb