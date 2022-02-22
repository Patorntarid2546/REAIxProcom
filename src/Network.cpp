#include "Network.h"

void Network::connect(char mode, string ip_s = ""){
    if(mode == 's')
    {
        sf::TcpListener listener;
        listener.listen(2000);

        if(listener.accept(socket) != sf::Socket::Done)
        {
            cout << "Error!\n";
        }
    }
    else if(mode == 'c')
    {
        if(socket.connect(ip_s, 2000) != sf::Socket::Done)
        {
            cout << "Error!\n";
        }
    }
}


void Network::senttext(string text){
    packet.clear();
    packet << text;
    socket.send(packet);
}

string Network::recievedtext(){
	string messageRec;
    if(socket.receive(packet) == sf::Socket::Done)
    {
        packet >> messageRec;
        return messageRec;
    }
	return "error";
}

