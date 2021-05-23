TARGET=project3.out

OBJS=main.o k-AVL.o
$(TARGET):$(OBJS)
	g++ $^ -o $@

%.o:%.cpp
	g++ -c $< -o $@

.PHONY:clean

clean:
	rm main.o k-AVL.o
