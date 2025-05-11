# Decorator design pattern

    - Decorator Pattern lets you add new features or behavior to an object without changing its original class by wrapping it in another object.

    - Think of it like this:

        - Imagine you're ordering coffee ☕.
            Base: Just plain coffee.
            Add-ons (decorators): milk, sugar, whipped cream, etc.

        - You don’t change the original coffee — you wrap it with add-ons, and each add-on adds something new.

    Step 1:

        interface Coffee {
            String getDescription();
            double getCost();
        }

    step 2:

        class BasicCoffee implements Coffee {
            public String getDescription() {
                return "Basic Coffee";
            }

            public double getCost() {
                return 5.0;
            }
        }

    step 3:

        class MilkDecorator implements Coffee {
            private Coffee coffee;

            public MilkDecorator(Coffee coffee) {
                this.coffee = coffee;
            }

            public String getDescription() {
                return coffee.getDescription() + ", Milk";
            }

            public double getCost() {
                return coffee.getCost() + 1.5;
            }
        }

    Usage:

        public class Main {
            public static void main(String[] args) {
                Coffee basic = new BasicCoffee();
                Coffee withMilk = new MilkDecorator(basic);

                System.out.println(withMilk.getDescription()); // Basic Coffee, Milk
                System.out.println(withMilk.getCost());        // 6.5
            }
        }

    ✅ Benefits:

        - Add new behavior without modifying existing code.
        - Follows Open/Closed Principle.
        - More flexible than subclassing.

    - This is super useful when the original class is from a library or someone else's code — or when it’s used in many places and shouldn't be touched.

    - If you try to add new behavior using inheritance (subclassing), you'll end up creating tons of subclasses.

        e.g., CoffeeWithMilk, CoffeeWithSugar, CoffeeWithMilkAndSugar, etc. 😵
        With decorators, you can mix and match behaviors without creating new classes for every combo