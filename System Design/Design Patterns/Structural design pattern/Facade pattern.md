# Facade design pattern

    - Facade Pattern provides a simplified interface to a complex system of classes, libraries, or APIs.
    - It hides all the complicated parts behind the scenes, so the user interacts with just one easy-to-use class.

    - Real-Life Analogy:

        - Imagine a universal remote for your home theater 🎮📺🎵:
        - You press one button (e.g., "Watch Movie")

        - Internally it:
            - Turns on the TV
            - Sets input to HDMI
            - Starts the sound system
            - Loads Netflix

        - You don’t have to do all of that manually — the remote is the facade!

    - Code Example

        - Subsystems (Complex parts)

        class DVDPlayer {
            void on() { System.out.println("DVD Player On"); }
            void play() { System.out.println("DVD Playing"); }
        }

        class Projector {
            void on() { System.out.println("Projector On"); }
        }

        class SoundSystem {
            void on() { System.out.println("Sound System On"); }
        }

    - Facade (Simple interface)

        class HomeTheaterFacade {
            private DVDPlayer dvd;
            private Projector projector;
            private SoundSystem sound;

            public HomeTheaterFacade(DVDPlayer dvd, Projector projector, SoundSystem sound) {
                this.dvd = dvd;
                this.projector = projector;
                this.sound = sound;
            }

            public void watchMovie() {
                System.out.println("Get ready to watch a movie...");
                projector.on();
                sound.on();
                dvd.on();
                dvd.play();
            }
        }

    - Usage

        public class Main {
            public static void main(String[] args) {
                DVDPlayer dvd = new DVDPlayer();
                Projector projector = new Projector();
                SoundSystem sound = new SoundSystem();

                HomeTheaterFacade homeTheater = new HomeTheaterFacade(dvd, projector, sound);
                homeTheater.watchMovie();  // Only one simple call!
            }
        }

    ✅ Benefits:

        - Simplifies the usage of complex subsystems
        - Reduces dependency between the client and the internal components
        - Makes the code easier to read and maintain

    📌 When to Use:

        - When you want to provide a simple entry point to a set of complex subsystems
        - When working with legacy systems or complex APIs

    🌱 Spring Boot as a Real-World Facade Example

        @SpringBootApplication

            - Is a facade for:

                @Configuration
                @EnableAutoConfiguration
                @ComponentScan

        It hides the complexity of the Spring internals and gives you a single simple interface — that’s Facade Design Pattern in action!