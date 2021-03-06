#include "Network.h"

void Network::connect(char mode, string ip_s = ""){
    if(mode == 's')
    {
        cout << my_ip << endl;
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
    cout << "error" <<endl;
	return "error";
}



double Network::recieveddouble(){
	string messageRec;
    if(socket.receive(packet) == sf::Socket::Done)
    {
        packet >> messageRec;
        return stof(messageRec);
    }
    cout << "error" <<endl;
	return 0;
}

void Network::sentpos(int i, double x, double y){
    x+=30; y+=35;
    string xx = to_string(x), yy = to_string(y), ii = to_string(i);
    senttext("pos");
    senttext(ii);
    senttext(xx);
    senttext(yy);
}