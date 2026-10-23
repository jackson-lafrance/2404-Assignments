a2: Control.o Date.o main.o Msg.o MsgArray.o Subscriber.o Telco.o Time.o View.o
	g++ -Wall -Wextra -std=c++11 -o a2 Control.o Date.o main.o Msg.o MsgArray.o Subscriber.o Telco.o Time.o View.o

Control.o: Control.cc Control.h
	g++ -Wall -Wextra -std=c++11 -c Control.cc

Date.o: Date.cc Date.h
	g++ -Wall -Wextra -std=c++11 -c Date.cc

main.o: main.cc Control.h defs.h
	g++ -Wall -Wextra -std=c++11 -c main.cc

Msg.o: Msg.cc Msg.h
	g++ -Wall -Wextra -std=c++11 -c Msg.cc

MsgArray.o: MsgArray.cc MsgArray.h
	g++ -Wall -Wextra -std=c++11 -c MsgArray.cc

Subscriber.o: Subscriber.cc Subscriber.h
	g++ -Wall -Wextra -std=c++11 -c Subscriber.cc

Telco.o: Telco.cc Telco.h
	g++ -Wall -Wextra -std=c++11 -c Telco.cc

Time.o: Time.cc Time.h
	g++ -Wall -Wextra -std=c++11 -c Time.cc

View.o: View.cc View.h
	g++ -Wall -Wextra -std=c++11 -c View.cc

clean:
	rm -f Control.o Date.o main.o Msg.o MsgArray.o Subscriber.o Telco.o Time.o View.o a2
