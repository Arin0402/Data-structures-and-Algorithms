# Flyweight design pattern

    - Also known as cache pattern
    - Flyweight Pattern is used to reduce memory usage by sharing objects that are similar or identical, instead of creating new ones every time.

    🧠 Real-Life Analogy:

        Think of a text editor 📝:

            - Every character on the screen is an object.
            - Instead of creating a new object for each letter A, we reuse the same A object for all instances.
            - Only the position (X, Y) and formatting (font size, color) might change.

        So you don’t have 100,000 different 'A' objects, just one shared 'A' object reused many times.

    🎯 Goal:
        
        Minimize object creation and save memory, especially when you have lots of similar objects.     

    - Example

        interface Shape {
            void draw(String color);
        }

        class Circle implements Shape {
            private String type = "Circle";  // Intrinsic data (shared (this is common))
            
            public void draw(String color) { // Extrinsic data (context-specific)
                System.out.println("Drawing a " + color + " " + type);
            }
        }

        import java.util.HashMap;
        import java.util.Map;

        class ShapeFactory {
            private static final Map<String, Shape> shapeMap = new HashMap<>();

            public static Shape getCircle() {
                if (!shapeMap.containsKey("circle")) {
                    shapeMap.put("circle", new Circle());
                    System.out.println("Creating new Circle object");
                }
                return shapeMap.get("circle");
            }
        }

        public class Main {
            public static void main(String[] args) {
                Shape redCircle = ShapeFactory.getCircle();
                redCircle.draw("Red");

                Shape blueCircle = ShapeFactory.getCircle();
                blueCircle.draw("Blue"); // Still the same circle object
            }
        }

        🧠 Only one circle object is created — reused with different colors (external data).

        ✅ Benefits:

            - Great memory optimization
            - Fast object reuse
            - Useful for systems with many repeated objects

        🚀 Used in:
        
            - Text rendering
            - Game engines (e.g. bullets, trees, clouds)
            - Document editors
            - Caching systems
                        
