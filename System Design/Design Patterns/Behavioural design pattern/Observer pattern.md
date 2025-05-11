# Observer design pattern

    - The Observer pattern is when one object (subject) keeps a list of dependents (observers) and notifies them automatically whenever its state changes.

    📱 Real-Life Analogy:

    Imagine you're subscribed to a YouTube channel:
        - The YouTube channel = Subject
        - You = Observer
        - When a new video is uploaded = Subject notifies all observers (sends notifications)

    You don’t have to ask repeatedly — you’re automatically informed when something changes.

    🧩 Components:

        Role	        Description
        
        Subject	        The main object whose state is being observed
        Observer	    Objects that want to be notified of changes
        Notification	Happens when the subject's state changes

    💻 Java Example: Weather Station    

    1. Observer Interface

        interface Observer {
            void update(String weather);
        }

    2. Subject Interface

        interface Subject {
            void addObserver(Observer o);
            void removeObserver(Observer o);
            void notifyObservers();
        }

    3. Concrete subject

        import java.util.ArrayList;
        import java.util.List;

        class WeatherStation implements Subject {
            private List<Observer> observers = new ArrayList<>();
            private String weather;

            public void setWeather(String weather) {
                this.weather = weather;
                notifyObservers(); // 🔔 notify everyone
            }

            public void addObserver(Observer o) {
                observers.add(o);
            }

            public void removeObserver(Observer o) {
                observers.remove(o);
            }

            public void notifyObservers() {
                for (Observer o : observers) {
                    o.update(weather);
                }
            }
        }
            
    4. Concrete Observers

        class PhoneDisplay implements Observer {
            public void update(String weather) {
                System.out.println("Phone Display: Weather updated to " + weather);
            }
        }

        class WindowDisplay implements Observer {
            public void update(String weather) {
                System.out.println("Window Display: Weather changed to " + weather);
            }
        }

    5. Test in Main

        public class Main {
            public static void main(String[] args) {
                WeatherStation station = new WeatherStation();

                Observer phone = new PhoneDisplay();
                Observer window = new WindowDisplay();

                station.addObserver(phone);
                station.addObserver(window);

                station.setWeather("Sunny ☀️");
                station.setWeather("Rainy 🌧️");
            }
        }

    ✅ Why Use Observer Pattern?

        Benefit	                        Why it matters
        📢 Loose coupling	            Subject doesn’t need to know details of observers
        🧠 Automatic notification	    Changes are instantly communicated
        🧱 Scalable	                    Easy to add/remove observers at runtime

# Difference bw Observer and Mediator


| Feature              | Observer                                | Mediator                                   |

| Communication Style  | One-to-many (Subject → Observers)       | Many-to-many via a central hub              |
| Who knows who?       | Subject knows observers                 | Mediator knows all colleagues               |
| Purpose              | To notify when state changes            | To coordinate actions between components    |
| Coupling             | Loosely coupled via subscription        | Decouples colleagues from each other        |
| Direction            | Unidirectional (Subject → Observer)     | Bidirectional (Colleagues ↔ Mediator)       |
| Control Flow         | Subject notifies all; no logic control  | Mediator controls who gets notified and how |

