# Lazel_Engine

Lazel Game Engine along Hazel Engine of TheCherno 

Hazel Engine Tutorial: https://www.youtube.com/watch?v=JxIZbV_XjAs&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=1



- EntryPoint System
  - clients are access to Lazel::CreateApplication()， which will return an APP-Instance that derive from Lazel::Application.
  - The main function will be included into Client's App from EntryPoint.cpp, in which the APP-Instance will be.

- Logging System
  - Based on [spdlog](https://github.com/gabime/spdlog) , controling actions by macros.

- **Event System**
  - Specific events are inherited from Lazel::Event. Each event contains member functions including GetStaticType() and GetEventType(), whichi will play as a key roll in EventDispatcher; 
  -  EventDispatcher dispatches an input event by comparing its static-type to the dispatcher's event-type. The DisPatch function reveieves input event as template T and an execute-function as argument, which will be executed if the above comaprition is positive.
- Window & Event
  - Window system is based on [glfw](https://github.com/glfw/glfw)
  - Set an EventCallback function of Application, including dispatch system. 
  - When window's callback functions are triggered, an specific event instance would be constructed and send to EventCallback function  
- Layer & LayerStack
  - LayerStack stores several Layers.
  - When **rendering or updating**, the layers in LayerStack would be **visited sequentially**.
  -  When **handling events**, the layers in LayerStack would be **visited revertially**.