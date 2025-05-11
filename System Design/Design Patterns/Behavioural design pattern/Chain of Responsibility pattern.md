# Chain of responsibility design pattern

    - A design pattern where a request is passed along a chain of handlers until one of them handles it.

    Each handler in the chain either:

        - Handles the request, or
        - Passes it to the next handler in line
    
    🧠 Real-Life Analogy:

    - Think of customer support:

        - You first talk to a bot
        - Then you're redirected to Level 1 support
        - If they can't help, it goes to Level 2, then maybe to a manager
    
    - Each level decides:

        “Can I handle this?”
        If yes → do it
        If no → pass it on 🔁

    - Java example

        abstract class Handler {
            protected Handler next;

            public void setNext(Handler next) {
                this.next = next;
            }

            public abstract void handleRequest(String request);
        }

        class Manager extends Handler {
            public void handleRequest(String request) {
                if (request.equals("leave")) {
                    System.out.println("Manager approved leave request.");
                } else if (next != null) {
                    next.handleRequest(request);
                }
            }
        }

        class Director extends Handler {
            public void handleRequest(String request) {
                if (request.equals("budget")) {
                    System.out.println("Director approved budget request.");
                } else if (next != null) {
                    next.handleRequest(request);
                }
            }
        }

        public class Main {
            public static void main(String[] args) {
                Handler manager = new Manager();
                Handler director = new Director();

                manager.setNext(director);

                manager.handleRequest("leave");   // Manager handles
                manager.handleRequest("budget");  // Passed to Director
            }
        }

    ✅ Benefits:

        Loose coupling between sender and receiver
        Flexible — you can add or change handlers without touching existing ones
        Follows Open/Closed Principle

    - Chain of Responsibility lets multiple objects try to handle a request, one after another, until one succeeds — like passing the buck 🔄


        
                