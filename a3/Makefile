a3: Control.o Date.o ExternMsg.o InternMsg.o Msg.o MsgList.o SubArray.o Subscriber.o Telco.o Time.o View.o main.o
	g++ -Wall -Wextra -std=c++11 -o a3 Control.o Date.o ExternMsg.o InternMsg.o Msg.o MsgList.o SubArray.o Subscriber.o Telco.o Time.o View.o main.o

Control.o: Control.cc Control.h Telco.h View.h
	g++ -Wall -Wextra -std=c++11 -c Control.cc

Date.o: Date.cc Date.h
	g++ -Wall -Wextra -std=c++11 -c Date.cc

ExternMsg.o: ExternMsg.cc ExternMsg.h Msg.h
	g++ -Wall -Wextra -std=c++11 -c ExternMsg.cc

InternMsg.o: InternMsg.cc InternMsg.h Msg.h Subscriber.h
	g++ -Wall -Wextra -std=c++11 -c InternMsg.cc

main.o: main.cc defs.h
	g++ -Wall -Wextra -std=c++11 -c main.cc

Msg.o: Msg.cc Msg.h Date.h Time.h
	g++ -Wall -Wextra -std=c++11 -c Msg.cc

MsgList.o: MsgList.cc MsgList.h Msg.h
	g++ -Wall -Wextra -std=c++11 -c MsgList.cc

SubArray.o: SubArray.cc SubArray.h Subscriber.h
	g++ -Wall -Wextra -std=c++11 -c SubArray.cc

Subscriber.o: Subscriber.cc Subscriber.h Msg.h
	g++ -Wall -Wextra -std=c++11 -c Subscriber.cc

Telco.o: Telco.cc Telco.h ExternMsg.h InternMsg.h MsgList.h SubArray.h Subscriber.h
	g++ -Wall -Wextra -std=c++11 -c Telco.cc

Time.o: Time.cc Time.h
	g++ -Wall -Wextra -std=c++11 -c Time.cc

View.o: View.cc View.h
	g++ -Wall -Wextra -std=c++11 -c View.cc

clean:
	rm -f Control.o Date.o ExternMsg.o InternMsg.o main.o Msg.o MsgList.o SubArray.o Subscriber.o Telco.o Time.o View.o a3
