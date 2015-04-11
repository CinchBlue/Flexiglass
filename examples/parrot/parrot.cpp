#include <iostream>
#include <string>

#include "Flexiglass.hpp"

class Parrot : public flgl::Event_Receivable
{
public:
    Parrot(flgl::Event_Queue& eq)
    :   listener(*this),
        sender(eq),
        counter(0)
    {
        eq.add_listener(listener.get());
        
        flgl::Event msg("console_output", "Parrot_initial");
        msg.push_data(std::string("Purrr..."));
        sender.send_event(msg);
    }
    
    ~Parrot()
    {
    }
    
    //Override the default event handler
    virtual void on_notify(flgl::Event& e) override
    {
        if (e.get_type() == "console_input")
        {
            if (e.get_name() == "phrase")
            {
                flgl::data_list dl = e.get_data();
                speak(dl);
            }
        }
    }
private:
    flgl::Event_Listener listener;
    flgl::Event_Sender sender;

    std::string current_str;
    int counter;
    
    void speak(flgl::data_list dl) {
        //Polly will repeat what you say.
        std::cout << "Polly says: \"";
        std::cout << flgl::unpack<std::string>(dl[0]) << "\"\n";
        
        ++counter;
        
        //Let's make Polly squack every 5 inputs.
        if(counter >= 5)
        {
            counter = 0;
            std::cout << "Polly squacks.\n";
        }
    }

};

int main()
{
    flgl::Event_Queue event_queue;
    Parrot polly(event_queue);
    flgl::Event_Sender console_input(event_queue);
    
    std::string str;
    std::cout << "Welcome to Parrot! Enter \"quit\" to quit!\n";
    
    while (str != "quit")
    {
        std::getline(std::cin, str);
    
        flgl::Event e("console_input", "phrase");
        e.push_data(str);
        console_input.send_event(e);
    
        while (!event_queue.empty())
            event_queue.process();
    }
    
    return 0;
}
