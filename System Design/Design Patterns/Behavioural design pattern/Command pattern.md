# Command pattern

    - https://www.youtube.com/watch?v=E1lce5CWhE0

    - Command Pattern is a way to turn a request (or action) into an object, so you can store it, pass it around, and run it later.

    -🔌 Real-life example:

        A TV remote:

        Each button (like "Power", "Volume Up") has a command behind it.
        Pressing a button calls execute() on that command.
        The remote doesn't care what the command does — it just triggers it.

    - You use an Invoker when you want clean separation, more control, or future flexibility in how and when commands are executed.
    - For tiny apps, it might feel extra — but in real-world systems, it becomes very useful!