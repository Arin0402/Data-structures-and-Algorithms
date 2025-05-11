# Mediator design pattern

    - The Mediator pattern defines an object (mediator) that centralizes communication between multiple objects, so they don’t talk directly to each other.

    🗣️ Real-Life Analogy:

    Imagine a chat room (like WhatsApp group or a Slack channel):

        - Users don’t message each other directly.
        - Everyone sends messages to the chat room.
        - The chat room (mediator) handles delivering the messages to others.

    This way:

        - Users don’t need to know about each other.
        - The chat room controls and manages communication.

    🤝 Without Mediator:
        Components talk to each other directly → tightly coupled → harder to manage.

    🧩 With Mediator:
        All components talk to mediator, and the mediator manages communication → loosely coupled and easier to maintain.

    - Java example

        interface ChatMediator {
            void sendMessage(String message, User user);
        }


        class ChatRoom implements ChatMediator {
            private List<User> users = new ArrayList<>();

            public void addUser(User user) {
                users.add(user);
            }

            public void sendMessage(String message, User sender) {
                for (User user : users) {
                    if (user != sender) {
                        user.receive(message);
                    }
                }
            }
        }

        class User {
            private String name;
            private ChatMediator chat;

            public User(String name, ChatMediator chat) {
                this.name = name;
                this.chat = chat;
            }

            public void send(String message) {
                System.out.println(this.name + " sends: " + message);
                chat.sendMessage(message, this);
            }

            public void receive(String message) {
                System.out.println(this.name + " receives: " + message);
            }
        }


        public class Main {
            public static void main(String[] args) {
                ChatRoom chat = new ChatRoom();

                User arin = new User("Arin", chat);
                User john = new User("John", chat);
                User emma = new User("Emma", chat);

                chat.addUser(arin);
                chat.addUser(john);
                chat.addUser(emma);

                arin.send("Hello everyone!");
            }
        }

    - Applicaitions

        - auciton/bidding system
