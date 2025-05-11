# Strategy design pattern

    - The Strategy Pattern lets you define a family of algorithms (or behaviors), put them in separate classes, and make them interchangeable at runtime.

    🎮 Real-Life Analogy: Payment Methods

        When you check out from an online store:

        - You can pay with credit card, PayPal, or UPI.
        - Each has its own logic.
        - You just pick one — no need to change the "Checkout" code!
    
    🧩 Key Parts

        Component	        Description

        Strategy	        Interface for the behavior/algorithm
        ConcreteStrategy	Different classes implementing the behavior
        Context	            Uses the Strategy and lets you switch them
    
    - Java example

    1. Strategy Interface

        - interface SortStrategy {
            void sort(int[] arr);
        }

    2. Concrete Strategies

        class BubbleSort implements SortStrategy {
            public void sort(int[] arr) {
                System.out.println("Sorting using Bubble Sort");
                // Dummy print — actual logic can go here
            }
        }

        class QuickSort implements SortStrategy {
            public void sort(int[] arr) {
                System.out.println("Sorting using Quick Sort");
                // Dummy print — actual logic can go here
            }
        }

    3. Context

        class SortContext {
            private SortStrategy strategy;

            public void setStrategy(SortStrategy strategy) {
                this.strategy = strategy;
            }

            public void performSort(int[] arr) {
                strategy.sort(arr);
            }
        }

    4. Main Class

        public class Main {
            public static void main(String[] args) {
                SortContext context = new SortContext();

                int[] data = {5, 2, 9, 1};

                context.setStrategy(new BubbleSort());
                context.performSort(data); // Bubble Sort

                context.setStrategy(new QuickSort());
                context.performSort(data); // Quick Sort
            }
        }

    
    ✅ Why Use Strategy Pattern?

        - Your can change behavior without modifying the main class
        - Removes if-else or switch logic
        - Easy to extend: Just add a new strategy class
        - Keeps different logics separated