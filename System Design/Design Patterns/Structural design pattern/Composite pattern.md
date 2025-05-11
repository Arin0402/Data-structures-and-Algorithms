# Composite pattern 

    - Composite Design Pattern lets you treat a group of objects and a single object in the same way.

    - It is used to build tree-like structures (like folders containing files and other folders), where both individual items and collections are handled uniformly.

    - Benefits of Composite Design Pattern

        1. You can treat individual objects and groups of objects in the same way.

            - For example: A File and a Folder (which contains files) both support .show().

        2. The code using these objects doesn’t need to know if it’s dealing with a single item or a group — it just works.

            - No need for if (isFolder) checks.

        3. Ideal for building hierarchical structures like.

            - File systems (folders/files)
            - UI elements (buttons, panels, containers)
            - Organization charts (employee, manager, department)

        4. You can add new types of components (new leaf or composite classes) without changing existing code — supports Open/Closed Principle.

    - ex:

        import java.util.ArrayList;
        import java.util.List;

        // Component
        interface FileComponent {
            void show();
        }

        // Leaf
        class File implements FileComponent {
            private String name;

            public File(String name) {
                this.name = name;
            }

            @Override
            public void show() {
                System.out.println("File: " + name);
            }
        }

        // Composite
        class Folder implements FileComponent {
            private String name;
            private List<FileComponent> children = new ArrayList<>();

            public Folder(String name) {
                this.name = name;
            }

            public void add(FileComponent component) {
                children.add(component);
            }

            @Override
            public void show() {
                System.out.println("Folder: " + name);
                for (FileComponent child : children) {
                    child.show();
                }
            }
        }
            

        - Here the client code can call the show() method on both file and folder so it does not differentaite between file and folder