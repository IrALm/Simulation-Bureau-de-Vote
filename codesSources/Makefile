CXX=g++
CFLAGS=-Wall -std=c++17 -g
INCLUDES=
LIBS=
TARGET=main
OBJ=main.o Personne.o BulletinVote.o Election.o Electeur.o Candidat.o EspaceIsoloir.o Salle.o Decharge.o Isoloir.o TableVote.o BureauVote.o

all : $(TARGET)

clean :
	rm -f $(TARGET) $(OBJ)

$(TARGET) : $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ) $(LIBS)

%.o: %.cpp
	$(CXX) $(CFLAGS) $(INCLUDES) -o $@ -c $<
