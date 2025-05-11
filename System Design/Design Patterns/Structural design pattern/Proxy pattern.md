# Proxy design pattern

    - A proxy is a placeholder or substitute for another object that controls access to it.
    - Proxy = middleman

    - Imagine you want to visit a celebrity 🧑‍🎤.

        You can't talk to them directly — you go through their agent (proxy), who:

        Controls access to the celebrity
        May allow, delay, or deny interaction

    - 🔍 Purpose of Proxy:

        - Control access to the real object
        - Add extra behavior (like logging, caching, or security) without changing the real object

    - Java example

        interface Internet {
            void connectTo(String site);
        }

        class RealInternet implements Internet {
            public void connectTo(String site) {
                System.out.println("Connecting to " + site);
            }
        }

        import java.util.*;

        class ProxyInternet implements Internet {
            private RealInternet realInternet = new RealInternet();
            private static List<String> blockedSites;

            static {
                blockedSites = Arrays.asList("facebook.com", "instagram.com");
            }

            public void connectTo(String site) {
                if (blockedSites.contains(site.toLowerCase())) {
                    System.out.println("Access Denied to " + site);
                } else {
                    realInternet.connectTo(site);
                }
            }
        }

        public class Main {
            public static void main(String[] args) {
                Internet internet = new ProxyInternet();
                internet.connectTo("google.com");      // Allowed
                internet.connectTo("facebook.com");    // Blocked
            }
        }

    ✅ Benefits:

        - Controls access to sensitive or resource-heavy objects
        - Adds extra behavior without modifying original code
        - Follows Open/Closed Principle

    - Proxy Pattern lets you intercept and control access to an object. It’s like a middleman that may add logic before or after the real thing is used.

    - Things that can be done using proxy pattern

        - Use for pre checks like if the request is valid or not, establishing connection, etc
        - Used for caching, if the real object is already present then return it
        - Preprocessing and postprocessing of data
        - Logging etc

    - In springboot, proxy is created for every bean