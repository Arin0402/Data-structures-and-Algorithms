# State design pattern

    - The State pattern allows an object to change its behavior based on its internal state, without changing its class.

    In short:

        "Change how the object acts based on what state it’s in."

    🧩 Key Components

        Component	            Description

        Context	                The main object that changes behavior
        State	                Interface or abstract class for all states
        ConcreteState	        Different classes implementing state behavior   

    - Java example

    1. State Interface

        interface FanState {
            void handleRequest(FanContext context);
        }

    2. Concrete States

        class OffState implements FanState {
            public void handleRequest(FanContext context) {
                System.out.println("Turning fan to LOW speed.");
                context.setState(new LowState());
            }
        }

        class LowState implements FanState {
            public void handleRequest(FanContext context) {
                System.out.println("Turning fan to HIGH speed.");
                context.setState(new HighState());
            }
        }

        class HighState implements FanState {
            public void handleRequest(FanContext context) {
                System.out.println("Turning fan OFF.");
                context.setState(new OffState());
            }
        }

    3. Context 

        class FanContext {
            private FanState currentState;

            public FanContext() {
                currentState = new OffState(); // default state
            }

            public void setState(FanState state) {
                currentState = state;
            }

            public void pressButton() {
                currentState.handleRequest(this);
            }
        }

    4. Main Class

        public class Main {
            public static void main(String[] args) {
                FanContext fan = new FanContext();

                fan.pressButton(); // OFF → LOW
                fan.pressButton(); // LOW → HIGH
                fan.pressButton(); // HIGH → OFF
            }
        }

    ✅ Output:

        Turning fan to LOW speed.
        Turning fan to HIGH speed.
        Turning fan OFF.
