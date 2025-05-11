# Template design pattern

    - Template Method Pattern lets you define the overall steps of an algorithm in a method, but allow subclasses to implement specific steps.

    ✅ So the template is fixed, but some steps can vary.
    
    🍳 Real-Life Analogy: Making Tea or Coffee

    The steps are:

        - Boil water
        - Brew (tea or coffee — varies!)
        - Pour in cup
        - Add condiments (like sugar/milk — varies!)

    🔁 The steps are the same, but how you brew and what condiments you add is different for tea vs coffee.

    - Java example

    1. Abstract Class

        abstract class Beverage {
            // Template Method
            public final void prepareRecipe() {
                boilWater();
                brew();
                pourInCup();
                addCondiments();
            }

            private void boilWater() {
                System.out.println("Boiling water");
            }

            private void pourInCup() {
                System.out.println("Pouring into cup");
            }

            // Steps to be customized
            abstract void brew();
            abstract void addCondiments();
        }

    2. Concrete Subclasses

        class Tea extends Beverage {
            void brew() {
                System.out.println("Steeping the tea");
            }

            void addCondiments() {
                System.out.println("Adding lemon");
            }
        }

        class Coffee extends Beverage {
            void brew() {
                System.out.println("Dripping coffee through filter");
            }

            void addCondiments() {
                System.out.println("Adding sugar and milk");
            }
        }

    3. Main Class

        public class Main {
            public static void main(String[] args) {
                Beverage tea = new Tea();
                System.out.println("Making tea...");
                tea.prepareRecipe();

                System.out.println("\nMaking coffee...");
                Beverage coffee = new Coffee();
                coffee.prepareRecipe();
            }
        }

    ✅ Why Use Template Method Pattern?

        - Common steps are reused in base class
        - No need to rewrite common code everywhere
        - Subclasses can change only what they need to
        - Template method is usually marked final

    - Use Template Method Pattern when you have an algorithm with fixed steps, but some of those steps may vary from class to class.