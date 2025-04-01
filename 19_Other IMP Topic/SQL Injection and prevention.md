# What is SQL Injection?
    
    - SQL Injection is a type of cyber attack where a hacker inserts malicious SQL code into a query to manipulate a database. This can allow them to access, modify, or delete data they shouldn’t have access to.

    - example

        Suppose a login system has this SQL query:

            SELECT * FROM users WHERE username = 'user' AND password = 'password';

        If an attacker enters admin' -- as the username, the query becomes: 

            SELECT * FROM users WHERE username = 'admin' --' AND password = 'password';

        The -- makes everything after it a comment, bypassing password verification and granting unauthorized access.

# Types 

    1. Classic SQL Injection (In-band SQLi)

        - The attacker sends malicious input and directly sees the database’s response.

        - Types:

            - Error-Based SQLi: Uses database error messages to extract information.
            - Union-Based SQLi: Uses the UNION SQL operator to combine results from different tables.

    2. Blind SQL Injection

        - The attacker doesn’t get direct error messages but infers data by analyzing application behavior.

        - Types:

            - Boolean-Based SQLi: Checks for true/false responses.
            - Time-Based SQLi: Uses time delays to determine if an injection is successful.

    3. Out-of-Band SQL Injection

        - Used when an attacker cannot see direct results or errors.
        - Instead of responses, attackers use techniques like DNS or HTTP requests to extract data remotely.

# How to Prevent SQL Injection?

    1. Use Prepared Statements (Parameterized Queries)

        - Instead of inserting raw user input into queries, use placeholders:
        - The database treats user input as data and not executable SQL code.

        - ex:

            String sql = "SELECT * FROM users WHERE username = ? AND password = ?";
            PreparedStatement stmt = connection.prepareStatement(sql);
            stmt.setString(1, username);
            stmt.setString(2, password);

    2. Use ORM Frameworks

        - Frameworks like Hibernate (Java) and Entity Framework (.NET) handle SQL safely.

    3. Validate and Sanitize User Input

        - Allow only expected characters in fields (e.g., only numbers for an ID).

    4. Limit Database Privileges
    
        - Use least privilege principles. A web app should only have access to necessary tables.

    5. Use Web Application Firewalls (WAFs)

        - They detect and block SQL injection attempts.