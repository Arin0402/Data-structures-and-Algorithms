# Memento design pattern

    - The Memento pattern is used to save and restore an object's previous state — without revealing its internal details.

    - Think of it like Undo/Redo functionality.

    - 🧻 Real-Life Analogy:

    Imagine you're typing in a Word document. Every time you press Ctrl+S, a snapshot of your work is saved.

        - When you hit Undo, it goes back to that saved version.
        - You don’t care how it's stored — just that you get your work back!
        - That's Memento Pattern in action.

    - 🧩 Key Components:

        Role	            Description

        Originator	        The object whose state you want to save/restore
        Memento	            A snapshot of the state
        Caretaker	        Manages saved states (like undo history)

    - Java example

    1. Memento Class (Snapshot)

        class TextMemento {
            private final String state;

            public TextMemento(String state) {
                this.state = state;
            }

            public String getState() {
                return state;
            }
        }

    2. Originator (Editor)

        class Editor {
            private String text = "";

            public void write(String newText) {
                text += newText;
            }

            public String getText() {
                return text;
            }

            public TextMemento save() {
                return new TextMemento(text); // saving current state
            }

            public void restore(TextMemento memento) {
                this.text = memento.getState(); // restoring old state
            }
        }

    3. Caretaker

        class Caretaker {
            private TextMemento savedState;

            public void saveState(TextMemento memento) {
                savedState = memento;
            }

            public TextMemento getState() {
                return savedState;
            }
        }

    4. Main Test

        public class Main {
            public static void main(String[] args) {
                Editor editor = new Editor();
                Caretaker caretaker = new Caretaker();

                editor.write("Hello ");
                caretaker.saveState(editor.save()); // save state

                editor.write("World!");
                System.out.println("Current Text: " + editor.getText());

                editor.restore(caretaker.getState()); // undo
                System.out.println("After Undo: " + editor.getText());
            }
        }

    ✅ Why Use Memento Pattern?

        Use Case	            Example

        🧠 Undo/Redo	        Text editors, drawing apps
        💾 Save/Load game	    Game state checkpoints
        🧪 Testing	            Snapshots for comparison
        🔧 Rollback logic	    Database transactions