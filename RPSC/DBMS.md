# Big data -> petabytes of data(1000 terabytes or 10^15 bytes)

    - five princliples -
        - volume
        - value =  the value of big data usually comes from insight discovery and pattern recognition that - - - lead to more effective operations
        - variety
        - velocity
        - veracity = the “truth” or accuracy of data and information assets, which often determines executive-level confidence

# DIKW pyramid

    - D = Data
    - I = Information
    - K = Knowledge (collection of information)
    - W = Wisdom (perform action using wisdom)

# Database

    - Collection of interelated data is known as database

# DBMS

    - DBMS is an appication software which manages and store database
    - permanent storage
    - rewuires secondary storage

    - examples
        - Oracle - Licensed
        - SQL SERVER - Licensed - MIcrosoft
        - Maria DB
        - Postgree SQL
        - MYSQL - open source - Oracle
        - DB2 - Licensed - IBM
        - NEO4G
        - SQlite
        - MongoDB
        - DynamoDB
        - MSAccess - Microsoft

# Data

    - two types
        - structured (stored in predefined structure)
        - unstructured (does not follow any predefined structure)

# File system

    - data redundancy ( Multiple sources have the copy of the original file). This leads to inconsistency if there is change in the original file

# Advantages of DBMS or disadvantages of file system

    - Redundancy ( removed by making the data centralised)
        NOTE: the redundancy that occur inside DBMS is known as normalization

    - overcame Inconsistency
        NOTE: Inconsistency occurs due to redundancy

    - concurrent access or execution using concurrency control protocols as it is centralised

    - role base security ( we can define roles to user and can access data based on that. This is not possible in file system)

    - Integrity (DBMS ensures acuuracy and correctness of data using integrity constraints )
        - There are no rules in file system to maintain integrity

    - reduced search time

    - transaction management
        - transaction = set of operations

# DBMS architecture

    - works on level of abstraction principle
    - it is bidirctional

    - types

        - level arch.

            - 3 levels
                - view/external lvl/conceptual lvl
                - logical (Intermediate lvl)
                - physical lvl (Internal lvl)
                    - B Tree
                    - B+ Tree
                    - Hash function
                    - Indexing etc are used

            - application developer works on the view level to create UI and display the data
            - DBA works on logical and physical level
            - Mapping between view and logical lvl is known as conceptual external mapping
            - Mapping between logocal and physical lvl is known as internal conceptual mapping
            - High order - view lvl
            - low order - physical lvl


        - schema arch.

            - schema = logical structure of database
            - level arch is also known as level schema (view schema, logical schema, physical schema)

            NOTE: View schema is also known as sub schema.

        - tier arch.

            - in order to get fast response, this architecture is used

            - types

                - single tier
                    - 1 tier
                        - When user and database works on the same system
                        - user has direct interaction with the database

                        - advantage
                            - cost effective
                            - easy to handle
                            - fast response

                        - disadvantage
                            - less secured
                            - not feasible

                    Note: not used in industry, used for practice only

                - multi tier

                    - 2 tier
                        - other name = basic client server architecture
                        - user and database are on different machines
                        - user can not direct interact with database
                        - user uses client application in order to access the database
                        - data is sent and transfered using api
                        - emxaple JDBC/ODBC

                        - advantage
                            - easy to handle/implement
                            - feasible for small business wesites

                        - disadvantage
                            - less throughput (number of outputs in per unit time) because everything (query processing, tracnsaction management etc) is done by dbms
                            - less secure

                    - 3 tier
                        - user and client application on one machine
                        - server applictaion and dbms on another machine

                        - advantage

                            - more throughput
                            - secure

# DBMS language

    - There are 4 components

    - DDL
        - create structure
        - delete strucutre
        - modify structure (not data)

        - commands
            - create
            - alter
                - add new column
                    - ALTER table bonus add interest FLOAT NOT NULL DEFAULT 0;

                - delete column (permanent)
                    - ALTER table bonus drop COLUMN_NAME

                - rename column/table
                    - alter table bonus rename column interest to saving_interest;

                - change column definition
                    - alter table bonus MODIFY interest DOUBLE NOT NULL DEFAULT 0;
                        OR
                    - alter table bonus alter interest DOUBLE NOT NULL DEFAULT 0;

            - drop
                - delete structure permanently
                - rollback not possible
            - truncate
                - permanently delete all the records
                - rollback is not possible
                - structure is not deleted

            - rename
                - used with alter comnd. (permanent rename)
                - to do tempororay renaming, we use alias AS.

                - NOTE: we do temporary renaminig in DQL

            - comment
                - 3 types of comments

                    - single line commt (--)
                    - multiple line commt (/* */)
                    - inline commt (-- or /* */)
                        - comments that are placed on the same line as a SQL statement.

    - DML
        - DQL
            - Select
                - Three clauses are there
                    - select clause
                        - It behaves as projection(∏) of relational algebra
                        - It uses aggregate functions also (max, min, count, avg, sum)

                    - from clause
                        - It behaves as cartesian product(x) of relational algebra

                    - where clause
                        - It behaves as selection(σ) of relational algebra

            - Temporary renaming using 'as' keyword
            - Tuple variable = The name given to the table using 'as' keyword is called tuple varibale
            - NOTE: only table name is considered. Attribute names are not considered


        - insert
        - update
            - to update multiple columns, use ','
            - update student set age = 12 , name = "sdfsdf" where id = 3;



        - delete
            - can be rollbacked untill it has not been commited

        - merge
            - also called UPSERT comnd.

        - call
            - call function or stored procedure

        - lock
            - to handle concurrency

    - DCL

        - grant
            - provide persmission for particular command
            -ex: grant Insert, Update ON student to user1, user2, user3;

        - revoke
            -ex: revoke Insert, Update ON student from user1, user2, user3;

        - these are part of Discretionary access control(DAC)

    NOTE: The parent class of DCL is DDL. (so of DCL is not in option then DDL)

    - TCL
        - Commit
        - rollback
        - savepoint
            - Creates a point within a transaction to roll back to if needed .

        - Savepoint is a type of Rollback comomand. It is an extension of rollback command


# DBMS user

    - types

    - Naive/Native/Parametric/End user
        - Parametric End Users are the unsophisticated who don’t have any DBMS knowledge but they frequently use the database applications in their daily life to get the desired results. For example, Railway’sticket booking users are naive users.

    - Application developer
        - also referred as System Analysts or simply Software Engineers, are the back-end programmers who writes the code for the application program

    - Sophisticated user
        - These are familiar with the database.
        -  They don’t write the program code but they interact the database by writing SQL queries directly through the query processor.
        - works on coceptual and physical level

    - Specialized user
        - These are sophisticated users
        -  They are proficient with specialized database applications, such as computer aided-design systems, knowledge-base systems, and expert systems.

    - Database designer
        - every database deisgner is sophistaced and specialized user

    - Database administartor/Super user

    - Casual/Temporary user
        - when a person uses database occasionally

        NOTE: a casual user is also end user

    - Regular user
        - uses database frequently

        NOTE: a regular user is also end user

    - Online user
        - access the internet using internet
        - also end user

    - Offline user

# DBMS models

    - Network model
        - 1960 - 1970
        - developed by charles w bachman
        - stores data in graph structure
        - database name IDS (Integrated Data Store)
        - No practical implementation

    - Hierarchical model
        - 1960 - 70
        - invented by IBM
        - Tree data strucutre was used
        - database name IMS (Information Management system)
        - No practical implementation

    - Relational model
        - 1970
        - Edger F. codd (Father of DBMS) IBM
        - no. of attributes/columns = arity/degree
        - no. of tuples/rows = cardinality

        NOTE: EC codd proposed a set of 13 rules with name "codd 12 rules"
        - Codd presents his 13 rules for a database to test the concept of DBMS against his relational model, and if a database follows the rule, it is called a true relational database (RDBMS). 
        https://www.javatpoint.com/12-codds-rules

    - ER model
        - Peter Chenn
        - used for database designing
        - pictorial representation


    - Object oriented model
    - Semi structured model
        - in this model, Attributes can accept different types of data values
        - XML (Extensible markup language) is used

    - NoSQL model

# Keys

     - selection procedure of primary key

        - Super key
            |
         candidate key
            |
          primary key

    - Super key
        - The set of attributes that can uniquely identify a tuple is known as Super Key
        -  It supports NULL values.

    - Candidate key
        -  A minimal set of attributes (columns) that can uniquely identify a record in a table.
        -  It can contain NULL values.
        -  If a subset of super key is already a super key then it is not considerd as a candidate key
            OR
           no subset of the candidate key can uniquely identify a record.

        - attributes of candidte key are called prime attributes.
            - ex: CK = AB, BC
                - so prime attributes are A,B,C

    - Primary key
        - unique and not null
        - candidate kwy which does not accept null value can be a primary key

    - Foreign key
        - table which contains primary key = referenced table
        - table which contains foreign key = referencing table

    - Alternate key/ Secondary key
        - rest of the keys from candidate key after selecting primary key

    - Composite key
        - key having more than one attribute

    - Compound key
        - key formed by 2 or more F.K

    - Unique key
        - accepts null values
        - ex: super key, candidate key, alternate key, composite key etc

    - Natural key
        - when the primary key is derived from the attribute the data itself then that primary key is known as natural key.
        - ex Roll no., passport no. etc

    - Surrogate key /  Aritificial key / Synthesis key / pseudo key / Database sequence no. / Unique sequence no.

        - when no attribute is eligible to become primary key, then another attribute is added which is knows as Surrogate key


# referential constraints for referenced table

    - Insert
        - no violation

    - Delete
        - may cause violation ( if the primary key exists in child table then error would be throen otherwise not)

        - solution
            - on delete cascade (deleted from child table first)
            - on delete set null
            - on delete restrict/no action

    NOTE: difference bw restrict and no action

        RESTRICT: Checks immediately when the delete or update statement is executed.
        NO ACTION: Checks at the end of the transaction.

    - Update
        - may cause violation

        - solution
            - on update cascade (updated from child table first)
            - on update set null
            - on update restrict/no action

# referential constraints for referencing table

    - insert
        - may cause violation (we tried to insert id in child table that does not exist in parent table)

    - delete
        - no violation

    - update
        -may cause violation

# Total no. of super keys

    - if there are n attributes in a table and all the attributes are candidate key
        - 2^n - 1

    - if there are n attributes in a table and there is 1 candiate key with k attributes
        - 2^(n-k)

        for ex:  N attributes as {A1, A2...An} and candidate key as {A1A2A3A4}, The total number of super keys will be 2^(N-4).

    - if there are n attributes in a table and there are 2 candiate keys

        for ex: If a relational model has N attributes as {A1, A2...An} and candidate keys as {A1, A2}, then the number of super keys?

            - for the first CK (A1), total no. of SK = 2^(n-1) (has single attribute only)
            - for the second CK (A2), total no. of SK = 2^(n-1) (has single attribute only)

            - now write both the CKs together = A1A2. So the total no. of attributes become = 2 and total no. of SK = 2^(n-2)

            - Final answer = (Total CKs of A1) + (Total CKs of A2) - (Together)
                        = 2^(n-1) + 2^(n-1) - 2^(n-2)


        IMP: If a relational model has N attributes as {A1, A2...An} and candidate keys as {A1A2, A2A3}, then the number of super keys?

            CK1 = A1A2
            CK2 = A2A3

            Now when we combine this, we would consider A2 only once.

            = 2^(N-2) + 2^(N-2) - 2^(N-3)

    - if there are n attributes in a table and there are 3 candiate keys

        - for ex: If a relational model has N attributes as {A1, A2...An} and candidate keys as {A1, A2, A3}, then the number of super keys?

        - Total super keys = 2^(N-1) + 2^(N-1) + 2^(N-1) - 2^(N-2) - 2^(N-2) - 2^(N-2) + 2^(N-3)

        (Take combinations)

# Query language

    - Two types

        - procedural query lang.

            - in this solution is also provided along with the problem
            - What we want and how we want

                - types
                    - Relational algebra
                    - PL SQL

        - non procedural/declarative query lang.

            - in this solution is not provided
            - What we want

                - types

                    - Relational calculas
                    - SQL

# Relational algebra

    - type of procedural query language
    - Procedures are called operations in relational algebra
    - there are two types of operations

        - basic operation
            - Select Operation( σ )
            - Project Operation( ∏ )
            - Union Operation( ∪ )
            - Set Difference( - )
            - Cartesian product( x )
            - Rename Operation( ρ )

        - advanced/additional/Extended  operation

            - Join( ⋈ )
            - Set Intersection( ∩ )
            - Assignment( ← )
            - Division( ÷, / )

        NOTE: advanced operations use basic operation behind the scene to execute query

# select operation( σ )

    - The select operation selects tuples that satisfy a given predicate.
    - also known as horizontal partitioning since it partitions the table or relation horizontally.
    - sysntax:

        σ p(r)

        - Where:

            σ is used for selection prediction
            r is used for relation
            p is used as a propositional logic formula which may use connectors like: AND OR and NOT. These relational can use as relational operators like =, ≠, ≥, <, >, ≤.


    NOTE:
        - it is a Unary operation ( works on one table at a time)
        - The selection operation is commutative that is,

            σ c1(σ c2(R)) = σ c2(σ c1(R))

    - ex:

        σ Place = 'Mumbai' or Salary >= 1000000 (Citizen)

# Project Operation( ∏ )

    - selects (or chooses) certain attributes discarding other attributes.
    - The Project operation is also known as vertical partitioning since it partitions the relation or table vertically discarding other columns or attributes.

    - syntax
        ∏ A1, A2, An (r)

        - Where

            A1, A2, A3 is used as an attribute name of relation r.

    NOTE:
        - it is a Unary operation ( works on one table at a time)
        - The Project operation removes duplicate tuples.
        - The Project operation is not commutative, that is :
            πAttribute List 1(πAttribute List2(R)) != πAttribute List 2 (πAttribute List1(R))

            - it is valid only if Attribute List 1 is a subset of Attribute List 2

# Rename Operation( ρ )

    - The rename operation is used to rename the output relation.
    - syntax:

        ρ X (R)

        - where

            the symbol ‘ρ’ is used to denote the RENAME operator and R is the result of the sequence of operation or expression which is saved with the name X.

    - Note:

        - Unary operator
        - the renaming operation is temporary

    - ex:

        - Rename Employee tabel to student
            ρ student (Employee)

        - Query to rename the attributes Name, Age of table Department to A,B.
            ρ (A, B) (Department)

        - Query to rename the table name Project to Pro and its attributes to P, Q, R.
            ρ Pro(P, Q, R) (Project)

        - Inorder to rename specific attribute, we can folow following methods

            - Query to rename the first attribute of the table Student with attributes A, B, C to P.
                ρ (P, B, C) (Student)

            - Query to rename the Eid of student to sid

                - syntax -     ρ (newName, oldName) (Relation)

                ρ (sid, eid) (Student)
                    OR
                ρ (sid/eid) (Student)

                - we can rename multiple by using ','.

                    ex: ρ (sid, eid), (sname, ename) (Student)
                            OR
                        ρ (sid/eid, sname/ename) (Student)


# Union Operation( ∪ )

    - Binary operation
    - Relation compatible condition is checked before applying set operations
        - no. of attributes should be same
        - type should be same
    - removes duplicate rows

    - syntax:

        - A ∪ S

        - to apply union on particular attrbutes

            (∏ A1, A2, An (r)) ∪ (∏ A1, A2, An (s))

    NOTE:
        - it is commutative A ∪ B = B ∪ A
        - it is associative  A ∪ ( B ∪ C ) = ( A ∪ B ) ∪ C

# Set Intersection( ∩ )

    - advanced operation
    - binary operation
    - Realtion compatible condition should be met
    - removes duplicate rows
    - syntax

        A ∩ S

        - it is commutative A ∩ B = B ∩ A
        - it is associative  A ∩ ( B ∩ C ) = ( A ∩ B ) ∩ C

    NOTE:

        INTERSECTION can be formed using UNION and MINUS as follows:

            A ∩ B = ((A ∪ B) - (A - B)) - (B - A)

# Set Difference( - )

    - A - S
    - removes duplicate rows
    - not cummulative
    - NOTE: it is associative

        = (R - S) - M = R - (S - M)

# Cartesian product( x )

    - binary operation
    - A x S
    - also called cross product
    - very high time complexity

# JOIN( ⋈ )

    - To minimize the time complexity of cartesian product, JOIN is used
    - When cartesian product is used with some condition, then it is called JOIN
    - binary operation

    - types

        - Inner join

            - Theta join (⋈θ)

                - Here θ represents condition except =.
                - also called Non equi join
                - works with any condition except =.
                - in SQL, it is called conditional join

                - ex: E ⨝ (E.Salary > D.MinSalary) D

            - Equi join (⋈=)

                - only works with '=' condition
                - ex:  Employees ⨝ (Employees.DeptID = Departments.DeptID) Departments


            - Natural join (⋈)

                - symbol same as join.
                - works on equal condition
                - joins the tables based on the columns name. The column name should be same and the valeus should be same also
                - common column appears only once in output table

                IMP: Total Attributes in output table = (Number of Unique Attributes in Table 1) +  (Number of Unique Attributes in Table 2) − (Number of Common Attributes)

                - Maximum and minimum number of attributes are  (m + n - 1) and 0

                ***** V.IMP:

                    - Minimum no. of tuples in natural join can be 0.
                    - Maximum no. of tuples in natural join can be m*n.
                    - NOTE: this is only possible when primary key - foregn key relation is not there in the table.

                    - for ex: we have coulm id in both the tables A and B. Table A 2 two tuples having value as 1. Table B have 4 tuples having value as 1. The output will be 2*4 = 8.

                    - But if id is primary key, then we can not have duplicate elements. Then the answer depends on primary-foreign key relation.



        - Outer join

            - IMP: in relational algebra, outer join is based on natural join.
            - Left outer join (⟕)

                - R ⟕ S

            - right outer join (⟖)
            - full outer join (⟗)

# Assignment operator(<-)

    - advanced operator
    - used to store the intermediate result of advance

    -ex: we have to perform A x B x C

        - R <- A X B

        - R X C

# Division operator (÷, /)

    - advanced operation

    - NOTE: Three basic operators are used

        - Cartesian product (x)
        - set difference (-)
        - projection (∏)

    - when 'all' or 'every' keyword is used in query then division operator is used

    - necessary conditions for join

        - we have two relations A and B. We want to perform A÷B or A/B, then

        - All the attributes of relation B should be proper subset of relation A. No extra attribute ahould be there in relation B.

        - The no. of attributes in the final result
            = Total attributes of A - Total attributes of B.

        - the no. of tuples in the final result
            = for all the values of attributes of B, the tuples should be there in A associated with same value attribute of A.

        - for ex:

        - This is relation A

            name | age
            -----
            a1 | b1
            a1 | b2
            a2 | b1
            a3 | b1
            a3 | b2
            a3 | b3

        - This is relation B

            age
            -----
            b1
            b2

        - the ouput of A/B

            name
            -----
            a1
            a3

        - Here,

            a1 and a3 are in the result because:

                (a1,b1) and (a1,b2) are in 𝑅
                (a3,b1) (a3,b2), and (a3,b3) are in R.

            However, a2 is not included because there is no pair (a2,b2) in 𝑅

    - steps performed (consider above example)

        - NOTE: firstly we find the values which are not going to be the part of the result. Then we set difference it from the first table to get the answer

        - 1.   Selcect the name attribute from A (it removes duplicate values)
            - ∏ name (A)

        - 2. create cartesian product of the above with raletion B

            ∏ name (A) × B

        - 3. Get the the disqualified tuples

            -  ∏ name (( ∏ name (A) × B ) – A)

        - 4. Get the desired result

            - ∏ name ( A )  −  ∏ name (( ∏ name (A) × B ) – A)

        - removes duplicate rows

# Relational calculas

    - non procedural
    - also called declarative language
    - What to do but never explain how to do
    - in relational calculas, expression is called formula

    - IMP: Relational algebra and Relational calculas are of same power but Safe Relational calculas and Relational algebra are considered to be more of same power.

    - Types

        - Tuple Relational calculas (TRC)

            - 1972
            - E.F codd
            - In this, every expression or formula is evaluated according to the tuple.
            - syntax

                {T | P (T)}   or {T | Condition (T)}

                    where
                        T is the resulting tuples
                        P(T) is the condition used to fetch T.

            - Operations used in formula

                - constants (numeric value)
                - variables (attributes name)
                - comparision operators ( <, >, <=, >=, =)
                - logical connector  ( OR (∨), AND (∧), NOT(¬))
                - Implication rule (x => y)

                    - Truth table

                        x   y   x => y

                        0	0	1
                        0	1	1
                        1	0	0
                        1	1	1

                    -IMP: p→q ≡ ¬p∨q (p→q  is equal to ¬p∨q)

                - It also uses quantifiers

                    - Existential Quantifier (∃) ("there exist")

                        - if single tuple staisfies the condition, then the answer is also true.

                    - Universal Quantifier (∀) (“for all” )

                        - all tuples should staisfy the condition.

                - NOTE:
                    - Those variables are used with quantifiers (∃, ∀) are called bound variables
                        ex: ∀x

                    - Those variables are used without quantifiers (∃, ∀) are called free variables
                        ex: age > 30

                - ex of TRC

                    {t| ∃ s ∈ loan(t[loan number] = s[loan number]
                           ∧ s[amount]>=10000)}



                - Unsafe expressions
                    - those expressions which can go in infinite loop
                    - ex: give the names of the stiudents which are not in a particular table. now this will go into infite loop as answer it not known(infinte)




        - Domain Relational calculas (DRC)

            - 1977
            - Results are filtered based on attributes

            - syntax

                {<a1,a2,a3,.....an> | P(a1,a2,a3,.....an)}
                - these are attributes

            - operations
                - same as TRC

            - NOTE: DRC filters data based on the attribute but always provides result in tuple form

            - ex of DRC

                {≺l≻ | ∃ b, a (≺l, b, a≻ ∈ loan ∧ (a ≥ 150))}

            - NOTE:
                - in TRC, only t is written at the left hand side while attribites names are written on the left hand side in DRC


# ER diagram

    - entity
        - real world object which exists independently
        - two types

            - tangible entity

                - exisits physically
                - person, car etc

            - intangible entity

                - exists logically
                - bank account

        - every row in a table is an entity

    - entity set
        - collection of entities that follow same attributes and properties
        - collection of rows

        - NOTE: a enetiy set can have single row also

        - two types

            - strong entity set
                - it has primary key.
                - if nothing is mentioned in question then it is by default strong entity
                - single reactangle

            -IMP weak entity set
                - it does not have primary key
                - it may have super, alternate, candidate key etc but not primary key
                - double rectangle

                - A weak entity has a Descriminator/partial key, which is an attribute (or a set of attributes) that can uniquely identify instances of the weak entity, but only when combined with the primary key of the strong entity.

                - The Descriminator/primary key for the weak entity is a composite key, formed by combining the partial key of the weak entity with the primary key of the strong entity. This composite key uniquely identifies each instance of the weak entity.

                - Descriminator/primary key is denoted by dashed line

                - IMP: The relationship between a weak entity set and a strong entity set is called an identifying relationship.

                - The strong entity set is called owner entity set.

                - It is always in total participation

                - cardinality is M:1 from weak to strong

    - entity type
        - table name is entity type

    - relationship set
        - shows realtion between entity sets

        - types

            - strong relationship set
                - relationship between all the strong entities
                - shown by siglw diamond

            - weak relationship set
                - if there is any one weak entity then it is weak entity
                - double diamond

        - properties

            - realtionship name should be unique

            - realtionship degree
                - no. of entity sets participating in a relation
                - minimum degree can be 1. This is called uniary relation.
                - if there are two enity sets with the same name, then it is considered as one only.
                - ex: employee manages employee
                    - this is uniary relaitonship

                - binary
                - ternary
                - quaternary
                - for more than 4 =  N-ary

    - cardinality

        - 1:1
            - reperesented using arrows or number
            - IMP: notice the direction

                - entity <-  Diamond  -> entity

        - 1:M
            - representation of M
                - by *
                - By M
                - IMP: if nothing is written then it is many


        - M:1
        - M:M

        - NOTE:
            - 1:M and M:1 are esentially the same thing.
            - It is not necessary for every entoy to make relation

    - participation

        - total participation

            - when all the entities of a entity set participates in a relation with some another entity set.
            - denoted by double or bold line
            - weak entity set has total participation

        - partial participation

            - denoted by single line

    - attributes

        - singlevalued and multivalued

            - singlevalued
                - denotion - oval

            - multivalued
                - denotion - double oval

        - simple and composite

            - simple
                - can not be broken down further
                - denotion - oval

            - composite
                - can be broken down further
                - denotion - oval with tree structure of ovals

        - stored and derived attribute

            - stored
                - attribute already present in database

            - derived
                - derived from stored attribute
                - denotion - dashed oval
                - ex: age

        NOTE: an attribute can be single valued and composite. ex: DOB

        - key and non-key attributes

            - key att.
                - att. which uniquely identifies
                - dention = underline

            - non-key
                - rest of the att.

        IMP: complex attribute

            - complex att. = mulitvalued + composite
            - ex: address

        - descrptive attribute

            - this is an attribute of relationship set.
            - this describes the association between the two entity sets
            - denotion - oval

# IMP: Mapping of ER model to relational model

    - there are few steps

    -1. Make seperate tables for all the enity sets.

    -2. Check cardinality

        - if cardinality is 1:1 or 1:M or M:1, then table for relation set is not formed
        - if cardinality is M:M, then table for relation set is formed

    -3. if multivalued attribute is given in any entity set, then seperate table is formed for that

    -4. For Weak entity set, the relation from weak to strong entity set is many to one.


    NOTE: In 1:1 or 1:M or M:1, realtionship table should be formed but we dissolve it in order to remove the data redundancy

        - Questions can come in exam related to the relationship set table of these cardinalitites although table is not formed.

        - for 1:1 or 1:M or M:1 cardinality

            - the attributes in relationship set table are

                P.K of table 1 + Pk of table 2 + descriptive attribute of relationship set

            - P.K can be be taken as either of table1 or table2.

            -NOTE: for 1:M or M:1, the relation table is merged with table having M relation.

        - for M:M cardinality

            - the attributes in relationship set table are

                P.K of table 1 + Pk of table 2 + descriptive attribute of relationship set

            - P.K would be the composite key fromed by P.K of table1 and table 2

# Minimum and maximum cardinality

    - minimum card.

        - The least number of relationships an entity (of entity set A) must have with another entities of entity set B.

    - maximum card.

        - The maximum number of relationships an entity (of entity set A) must have with another entities of entity set B.

    - ex: two tables student and course.

        - s1 is associated with c1, c2, c3
        - s2 is associated with c1, c4
        - s3 is associated with no one

        - so the minimum card. is 0 and the maximum card. is 3.

    -NOTE: In ER diagrams, this is shown by (minimum card, maximum card)

            - like (0, 3).

# Advanced/Extended ER diagram featrues

    - Specialization

        - denotion = inverted triangle
        - it is top to bottom
        - Top ennity = higher order entity
        - Leaf entity = lower order entity

    - Generalization

        - denotion = inverted triangle
        - it is bottom to up

    - Aggregation

        - In ER model, a relationship set can't be connected to another relationship set directly.
        - This is a limitation of ER Model
        - To remove this limitation, we use aggregation
        - The relation formed between two entity set is considered as abstract entity set.
        - This abstract entity set can be related to another realationship set

# SQL

    - History

        - developed by IBM in 1970
        - scientists
            - Donald Chamberlin
            - Raymond boyce

        - Intially it was called SEQUEL (Structured EnglishQuery Language)
        - Developed in San Jose labarotary
        - It is adomain specific language

        - It uses both relational algebra and relational calculaa but maximum uses relational algebra

        - In 1986/87, ANSI/ISO approved SQL so it is also called ANSI/ISO SQL
        - First version of SQL-86
        - Latest Version SQL-2022

    - SQL by default gives duplicate values where as relational algebra gives unique values

    - Two types

        - PLSQL = procedural
        - SQL = non procedural

# SQL architecture

    -       Query
              |
            Query processor -> Query optimiser
              |
            SQL Engine -> File manager
              |
            Secondary storage

    - Query goes to Query processor
    - Query processor takes help of Query optimiser to reduce the query
    - Optimised query comes to SQl engine
    - Sql engine anaylses the query
    - Sql engine takes help of File manager

# Set operations in SQL

    -1. Union (removes duplicacy)
        - select * from table1
            union
          select * for table2

    -2. Union all (includes duplicate rows)

    -3. Intersect
        - select * from table1
            intersect
          select * for table2

    -4. Intersect All (includes duplicates rows)

    -5. Except (set difference)

        - select * from table1
            except
          select * for table2

        - NOTE: it removes duplicates entries from first table which are not in table2.

    -6. Except All (includes duplicates  rows)

# JOIN in sql

    -1. Cross join
        - cartesian product
        - no condition

        - select * from student, course;

    -2. Inner join

        - conditional join
            - same as theta join of R.A

        - equi join
            -ex: select * from student
                 inner join
                 course on student.id = course.id;

                 OR

                 select * from student, course where  student.id = course.id;


        - natural join

    -3. Outer join

        - left outer join
        - right outer join
        - full outer join

    -4. Self join
        - works on two tables (both the tables are same).
        - ex: student table

            sid     cid

            s1      c1
            s2      c2
            s1      c2

        - find the students whoch are enrolled in more than one course

            - select distinct t1.sid from student as t1, student as t2 where t1.sid = t2.sid and t1. cid <> t2.cid.

            - ans = s1.

            NOTE: <> (not equal to sign)

# Aggregate functions

    - min
    - max
    - sum
    - avg
    - count

    NOTE: in relational algebra, these functiona are represented by caligraphic G.

        -ex:    G min(salary) Employee

    NOTE:
        - Aggregate functions ignore NULL values.

        - On numeric data, all agg. functions apply
        - On non numeric data, only count, min and max applies. (min, max counts the no. of characters)

        - count(*) does not avoid null values even if all the values in the row are null

# Group by

    - the columns list after the select and after the group by should be the same always.
    - ex:

        SELECT column1, column2, aggregate_function(column3)
        FROM table_name
        GROUP BY column1, column2;

    - Having clause with Group by

        - Filters groups of rows after aggregation has been performed.
        - Used to specify conditions on aggregated data (i.e., results of GROUP BY).

# Operators in SQL

    - Airthmetic operators
        +
        -
        *
        /
        %

        NOTE:
            - 5 + NULL = NULL.
            - Doing airthmetic operation with NUL results in NULL.

    - Relational

        =
        != or <>
        >
        <
        >=
        <=
        !< (not less than)
        !> (not greater than)

        - these give true or false

        NOTE: If any of the operand is NULL, then the output is also NUll

            -ex: 5 > NULL
                 = NULL

    - Logical operators

        - AND
        - OR
        - NOT
        - ALL
        - IN
        - EXISTS
        - BETWEEN
        - UNIQUE
        - ANY
        - LIKE
        - IS NULL
        - SOME

        NOTE: If any of the operand is NULL, then the output is also NUll

# SQL execution of query sequence

    - from > join > where > group by > having > select > distinct > order by > limit

# Datatypes

    - string datatype
        - char(size) 0 to 255.
        - varchar(size) 0 to 65535

    - Numeric datatype
        - int
        - long int

        - floating

            IMP:  - numeric(p, d)
                        - p denotes total no. of digits in number
                        - d denotes no. of digits after decimal
                        - ex: numeric(3, 1) => 33.5
                        - this is user defined

            - float(n)
                - n denotes maximum precision after decimal
                - this is user defined

            - double/real
                - machine defined.
                - no need to mention length

    - Date & time datatype

        - Date
            - format YYYY-MM-DD

        - TIME
            - HH-MM-SS
                or
            - HH-MI-SS

        - DATETIME
            -  YYYY-MM-DD hh:mm:ss

    - BLOB
        - Binary large object
        - Used to store image/video/graphics

# Integrity constants

    - six types
        - NOT NULL
        - UNIQUE
        - PRIMARY KEY
        - FOREIGN KEY
        - CHECK
        - DEFAULT

# Subquery

    - two types

        - Nested subqueries
            - mainly IN/NOT IN are used
            - Bottom up approach
            - firstly inner query is executed and then outer query
            NOTE: It is necessary to use brackets for nested subquery

        - Corelated subqueries
            - mainly EXISTS/NOT EXISTS are used
            - Top to down approach
            - outer query is executed first

            -ex: select * from student
                 where sid exists (select sid from course where student.sid = course.sid)

    NOTE: Join is faster than subquery but takes more space.
          - In the MCQs, always prefer join.

# View

    - virtual table
    - syntax
        - create view stu_view as select sid, name, age from student;
        - drop view stu_view

    - we can update, delete, insert row in a view
    - Rename view also

    NOTE: Inserting a row into an updatable view will impact the underlying table by adding a corresponding row. The data modification is propagated to the underlying table that the view is based on.

    - For the view to be updatable, it should meet certain conditions, such as:

        - The view must reference exactly one table.
        - The view should not include any aggregate functions, DISTINCT, GROUP BY, HAVING, UNION, or JOINs on more than one table.
        - All columns referenced in the view must be from the underlying table.
        - The view should not contain any subqueries in the SELECT clause.
        - The view should not use any set operations like UNION, INTERSECT, etc.

# PLSQL

    - developed by oracle
    - 1980
    - Procedural language
    - What to do & how to do
    - We don't write query in this. We write code or programming block
    - In PLSQL, SQL is used but in SQL, PLSQL is not used

    - It is written in three parts

        - Declaration block (optional)
            - to declare variables

        - Executable block (mandatory)
            - main code
            - start with BEGIN keyword
            - ends with END keyword

        - Exception handling (optional)

    - syntax

        - Declare

            // code

          BEGIN
            // code

            EXCEPITION HANDLING
            // code

          END

    - Four things widely used in PLSQL

        - procedure
            - It is a sub program that performas some action
            - It does not return any value (this is the difference bw procedure and function)
            - syntax
                - Declare
                  create or replace procedure PR_NAME as
                    // code

                BEGIN
                    // code

                    EXCEPITION HANDLING
                    // code

                END

        - function
            - returns value
            - syntax
                - Declare
                  create or replace function FN_NAME as/in
                    // code

                BEGIN
                    // code

                    return()

                END

        - trigger
            - it is a stored program that executes automatically if any event occurs
            - basically used in DML, DDL, database operations (login, logoff)
            - a trigger can be defined on only one table
            - a table can have maximum 3 triggers

        - cursor
            - It is used when any SQL statement is processed in order to point the memory where the query is being processed
            - This area is also called context area and it is controlled by cursor

            - two types

                - implict
                    - forms automatically

                - explicit
                    - created by writing code or block

# Functional dependency

    - given a table

        x   y

        x1  y1  -> tuple 1 (t1)
        x2  y2  -> tuple 2 (t2)

    - x -> y  <=> { t1t2 belongs to R (t1.x = t2.x) => (t1.y = t2.y)}

    - (x -> y) is a functional dependency if right hand side is true. (=> this is the sign of implication)

    - if right hand side is true, then x -> y is a functional dependency

    - Simply explainned

        if we have tuples like

            name  age
            A     10
            B     20
            A     30

            - name -> age is not a functional depencdency as A has two values (10 and 30).
            - for this to be functoional dependency, for all appearences of A, the value of age should be same

    - A table should have as minimum FD as possible.
    - FD leads to data redundancy

    - types

        - Trivial FD
            -  x -> y is a Trivial FD if

                - x is a superset of y OR x is equal to y

        - Non Trivial FD
            - x is not a superset nor equal to y

    - properties of FD

        - Reflexive

            - if x is a superset of y, then it is called reflexive property

        - transitive

            - if A -> B and B -> C

                then A -> C

        - Splitting property

            - if A -> BC

                then A -> B and A -> C

        - Augmenting

            - if A -> B

                then AC -> BC  is also FD. (Attribute should be same both the side)

        - Union

            if A -> B and A -> C

                then A -> BC

    - Attribute closure (IMP)

        - refers to the set of all attributes that can be functionally determined by a given set of attributes.

        - denoted by X^+ ( + is in superscript )

        - for example (DBMS class 46, at 25 min)

        - IMP: finding super key when FDs are given.

                - if colsure of an attribute consists of all the attributes then it can be super key

# Anomalies

    - redundancy in database can occur due to two reasons
        - high functional dependency
        - multivalued attributes

    - types of anomalies
        - insert
        - update
        - delete

        - consider example of table having student details, course and teacher details.

        - update anomaly
            - updated the detail of teacher in one tuple but not in another

        - insert anomaly
            - We want to insert new teacher teaching new course but student is noe available so can't be inserted

        - delete
            - deleted a teacher, now no other occurence is present in the table


    - solution

        - decompostion of table

            - types
                - Lossless decomposition
                    - If table R is decomposed into two tables R1 and R2, then in future if we rejoin R1 and R2, we should get R back. The data should be equal. Not greater nor lesser.

                    - if it is not possible then it is lossy decomposition

                - dependency preserving
                    - the dependency which are in parent table should be there in decomposed tables also


        - Rules for lossless decomposition

            - three rules

                - R1 U R2 = R  (the union of attributes of R1 U R2 should be equal to attributes of R)

                - R1 ∩ R2 != phi(empty)

                - The common attribute of R1 and R2 should be either the super key of R1 OR R2 OR both

            - Q. 47 book (DBMS. 5 (page no.))

# Normalization

    - heart of DBMS
    - Used to reduce or remove the redundancy
    - It uses two methods
        - lossless decomposition
        - dependency preserving

    - When we decompose the table, then it determines which attribute would go in which table

    - Normal form = set of rules for removing or reducing redundancy

    - Normal forms

        - 1 NF
        - 2 NF
        - 3 NF
        - BCNF
        - 4 NF
        - 5 NF

        NOTE:
            - In 1 NF, 2 NF, 3 NF and BCNF, the redundancy that occur due to functional dependency is removed
            - In 4 NF, the redundancy that occur due to multivalued attributes is removed
            - In 5 NF, the redundancy that occur due to Join dependency  is removed

            - If the table is in BCNF, then 100% functional dependency redundancy is removed

            - 3 NF follows lossless decomposition and dependency preserving but in some cases, BCNF does not follow dependency preserving. That's why 3 NF is considered best refinement for a table

# 1 NF

    - Atomic value should be there for each attribute
    - For a domin to have atomic value, it should be indivisible

# 2 NF

    - must be in 1 NF
    - No partial functional dependency should be there
    - only fully functional dependency should be there

    - partial functional dependency

        Y -> A is a PFD if Y is a proper subset of candidate key and A is a non prime attribute

        in simple words,
        take ex:  AB -> C, C -> D, B -> E. Here AB is a candidate key( find out by taking closure)

                so AB -> C is a fully functional dependency as AB is not a proper subset of AB
                   C -> D is fully functional dependency as C is not a proper subset of AB
                   B -> E is partial functional dependency as B is proper subset of AB

        here AB is candidate key so part of it should not determine a non prime attribute

    - A relation will be in 2NF if it is in 1NF and all non-key attributes are fully functional dependent on the primary key.

# 3 NF

    - must be in 2NF
    - no any transitive functional dependency

    - transitive functional dependency

        Y -> A is a transitive functional dependency if Y is not a super key and A is a non prime attribute

        OR

        Y -> A is not a transitive functional dependency if Y is a super key or A is a prime attribute.

        - So according to second definitaion,
            if we have
                X -> A where X is a non prime attribute and A is a prime attribute then this is also 3 NF

# BCNF

    - must be in 3 NF
    - also called strict normal form
    - the LHS attrinbute should be atleast super key.

        - by this, the drawback of 3NF (See exmple in 3NF (second definition)) is overcomed

# 4 NF

    - must be in BCNF
    - no multivalued functional dependency

        sign of multivalued dependency = ->->

# 5 NF

    - must be in 4 NF
    - No join dependency should be there
    - It ensures that the decompostion is losless till now
    - It is also called Project-join normal form

# IMP Example 1

    AB -> C
    C -> DE
    E -> F
    F -> A

    find the highest normal form of this.

    NOTE: for these type of questions, we consider till BCNF only and these are already in 1 NF


    ans.

        1. Find the candidate keys for this.

            - AB is a clear candidate key which can be found using closure
            - now, Golden rule, if the prime attribute of a candidate key appears on the right hand side, then the left hand side attribute can be considered for primary key.

            - here A and B are prime attributes.
            - A appears on the right hand side in FD F -> A.
            - so FB is also a candidate key. (confirm by finding the closure of FB)
            - by this , EB is also a candidate key and CB is also a candidate key

            - so candidate keys are AB, FB, EB, CB and prime attributes are(A, B, F, E, C)

        2. check 2 NF first

            - since CB is a candidate key and C -> DE is there so partail dependency exists
            - hence not in 2 NF

    - so the answer is 1 NF

# IMP Example 2

    A -> B
    D -> E

    find candidate key

    ans.
        - Here you would see that by taking closure, we wouldn't be able to find the candidate key.
        - so in this type of question, we take the range.
        - the range of alphabets is from A to E.
        - C is missing from these FD
        - so take the closure of the whole set ABCDE.
        - the clousre would be ABCDE itself
        - now drop the attributes which are being determined in the above FDs
        - so drop B and E
        - now we are remain with ACD.
        - this is our candidate key

# Canonical / minimal / irreducable cover

    - If we are given a set of FDs then to remove some FDs or reduce the size of the FD set is called cannonical cover

    - steps

        for ex:

            A -> B
            C -> B
            D -> ABC
            AC -> D

        1. remove Trivial dependency (like A -> A, AB -> A)

            - in the above exmaple, none is there

        2. right hand side of FD should have single attribute

            - so the above example reduces to

                A -> B
                C -> B
                D -> A
                D -> B
                D -> C
                AC -> D

        3. Take every FD one by one and check if we can remove that. For this, find the closure of the aatributes at left hand side and do not consider this FD for finding closure. If all the attributes of the given set occurs in the closure then we can remove it.

            -ex:

                for A -> B, find closure of A by usign remaining FDs

                    C -> B
                    D -> A
                    D -> B
                    D -> C
                    AC -> D

                - By this, closure of A turns out to be A itself. So we can not remove it.

                - Try for every FD like this.

                - For D -> B,

                    A -> B
                    C -> B
                    D -> A
                    D -> C
                    AC -> D

                    try finding clousre of D in the above FDs. Turns out we can remove D

        4. Try to remove composite attribute on the LHS

            - Here only AC -> C is a composite attribute
            - so for AC
                - try removing A and find if A appears in the closure of C. if A appears than remove AC.
                - similarly try removing C and find if C appears in the closure of A. if C appears than remove AC.

            - it turns out we can not remove AC.
            - Hence the above is our canonical cover

# Equivalence of FD

    - class 51, 41:00

    - given two FD set X and Y, they are eqivalent when X covers Y and Y covers X.

# Transaction management

    - operations on DB
        - read operation
        - write operation
        - commit

    - Properties of transaction

        - ACID

        - Atomicity(All or none/nothing rule)
            - either the entire transaction takes place at once or doesn’t happen at all. T
            - manages by Transaction manager

        - Consistency

            - This means that integrity constraints must be maintained so that the database is consistent before and after the transaction. It refers to the correctness of a database. Referring to the example above,
            The total amount before and after the transaction must be maintained.
            Total before T occurs = 500 + 200 = 700 .
            Total after T occurs = 400 + 300 = 700 .
            Therefore, the database is consistent .

            - it is the responsibility of application programmer

        NOTE: If in a transaction, Atomicity, Isolation and Durability are fulfilled then Consistency would be by default fulfilled

        - Isolation
            - This property ensures that multiple transactions can occur concurrently without leading to the inconsistency of the database state.
            - maanged by Concurrency Control Manager/concurrent execution manager

        - Durability
            - This property ensures that once the transaction has completed execution, the updates and modifications to the database are stored in and written to disk and they persist even if a system failure occurs.
            - managed by Recovery Manager

# Transaction states

    - https://www.geeksforgeeks.org/transaction-states-in-dbms/

    NOTE:
        - Resource allocation happens in active state
        - Resource deallocation happens in active state

# Schedule

    - execution sequence of multiple transactions

    - two types

        - Serial schedule

            - other transaction won't start untill the first transaction has completed
            - they would take place serially
            - number of possibilites = n! (n = no. of trnasactions)

            - advantage
                - always consistent
                - more secure

            - disadvantage
                - waiting time is more
                - throughput (output in per unit time) is less

        - parallel schedule

            - multiple tranactions are taking place simlutaneously

            - adavntage
                - waiting time is less
                - Throughput is more

            - disadvantage
                - can be inconsistent

        - the best soultion is to use parallel transaction but make it behave like serial transaction

# problems in parallel transaction

            1. Dirty read prob. (IMP) (Most questions come from this)

                - this is also called

                    - uncommitted read prob.
                    - read after write prob. (RAW)
                    - write-read prob.
                    - write-read conflict prob.

                - if a transaction reads the value from another trancsaction that has not been committed yet, then it is called dirty read problem.

                - ex:  let A = 100

                        T1          T2

                        R(A)
                        A = A -50
                        W(A)
                                    R(A)
                                    A = A-10
                                    W(A)
                                    commit

                        failed

                    - these Read write operations are taking place in the ram itself until not committed.
                    - Here the trans. T2 read the value of A as 50 and made changes to the database as A = 40
                        but trans. T1 failed and because of that the value of A should be 100.
                    - This is dirty read as trans. T2 used wrong value of A.

                    - trans. T1 does not fail, then there would be no problem, but it can fail also


            2. Lost update prob.
                - also called write-write prob.

                - When the write update of one transaction is lost due to another transaction

                - ex:  let A = 100

                        T1          T2

                        R(A)
                        A = A-50
                        W(A) // 50
                                    A = A - 50
                                    W(A) // 0
                                    commit // 0

                        commit // 0


                    - NOTE: a trans. can write wtihout even reading. This is called blind write.

                    - Here trans T1 wants to update the value as 50, but ends up updating value as 0

            3. Phantom read prob.

                - ex:  let A = 100

                        T1      T2

                        R(A)
                                R(A)
                                delete(A)

                        R(A)

                    - here T1 would try to read the value of A but it does not exist. this is called phantom read problem

            4. Incorrect summary prob.

                - when aggregate functions are used in transactions then this problem occurs
                - basiclly similar to dirty read problem

            5. Unrepetable read prob.

                - If a trans. reads a value and after some time it again reads the value, then it is different. This is called uprepetable read problem

                - ex:  let A = 100

                        T1          T2

                        R(A) //100
                                    R(A)
                                    A = A - 50
                                    W(A)
                                    commit

                        R(A) // 50


                        - in the second R(A) of trans. T1, it gets value 50. this is wrong

NOTE: - if in a schedule, the transactions do not interleave with each other then this is called serializable schedule.  
 - serial schedule is always serializable schedule.  
 - serializable schedule are always consistent

    - like T1 -> T2 -> T3

# Serializability (IMP)

    - process of conversion a parallel schedule into serializable schedule

    -IMP: two methods are used

        - conflict serializability

            - precedence graph is used
            - if precedence graph has no cycle or loop then conflict serializability is achieved
            - if conflict serializability is achieved then schedule is serializable and consistent
            - if precedence graph has loop, then no conflict serializable but it does not answer that the schedule can be serialized or not. For that, in order to find out, we use view serializability

            - ex: class 55 at 39:00

            - conflict equivalent

                - creating the serial schedule of a parallel schedule by swapping the non conflicting operations is called conflict equivalent
                - if conflict equivalent can be made then, schudle becomes serializable

                - ex of conflicting and non conflicting

                    T1          T2

                    R(A)        R(A)  (non conflicting)
                    R(A)        W(A)  (conflicting)
                    W(A)        W(A)  (conflicting)
                    W(A)        R(A)  (conflicting)

                    R(A)        R(B)  (non conflicting)
                    R(A)        W(B)  (non conflicting)
                    W(A)        W(B)  (non conflicting)
                    W(A)        R(B)  (non conflicting)

                - ex:

                    T1          T2

                    R(A)
                                R(B)
                                W(B)
                    W(A)

                    - This can be converted to

                    T1          T2

                    R(A)
                    W(A)
                                R(B)
                                W(B)

                    - Hence this is conflict equivalent and serializable
                    - we start from bottom statement and try to swap the bottom two operations if they are not conflicting

                - ex:

                    T1          T2

                    R(A)
                                R(A)
                    W(A)

                    - This can't be converted as it is conflictiing

                NOTE: conflict equivalent and conflict serializability are different thing

        - view serializability

            - it is used to find out if a schedule is serializable schedule or not

            NOTE: 
                - if a schedule is conflict ser. then it is also view ser.
                - so if question comes in exam to check view serializability then we can also check conflict ser.

            - we create view equivalent of given schedule. If view equivalent is there then it is view serializable.

            - ex: class 56 (from starting) till 49:00

            - for view ser. , it is important to have blind write

        - IMP:  To check if a schedule can be serialized or not

                1. check conflict ser. first
                    - if it is true, then possible
                    - if false, go to 2.


                2. check if any blind write is there
                    - if yes, check view ser.
                    - if not, then view ser. not posible

# Recoverability

    - sometimes a transaction is not able to get executed completely due to software/hardware issues etc. That transaction is rolledbacked and the database should be consistent as before.

    - types

        - irrecoverable schedule

            - if a trans. T2 dirty reads from T1 and post that T2 commits and T1 fails then this is irrecoverable

        - recoverable schedule

            - cascading schedule
                - if a transaction fail, then rollback other trnsactions also but the condition is other transactions should not have been committed.

            - cascadeless schedlue
                - It does not allow dirty read but write-write (blind write) is allowed

            - strict schedule
                - No dirty read and no write-write allowed

# Concurrency control protocol

    - In order to achieve serializability and recoverablity in parallel schedule, these protocols are used.
    - types

        - lock based protocol (IMP)
            - types
                - Shared Exclusive lock

                    - shared lock (S)
                        - ex: S(A)
                              S(B)

                        - with shared lock, only read is possible

                    - exclusive lock
                        - ex: X(A)

                        - with exclusive lock, read and write both are possible

                    - U is for unlock

                    - ex:

                        T1          T2

                        X(A)
                        R(A)
                        W(A)
                        U(A)        S(B)
                                    R(B)
                                    U(B)

                    NOTE:
                        - If a transaction has shared lock on a item and other transaction wants to acqure shared lock on that item, then it is granted.
                        - In any other case like (X, S), (S, X) or (X, X), the lock to second transaction is not granted

                    - disadvantages
                        - It does not gurantee serializability
                        - It can lead to irrecoverable schedule
                        - May also lead to deadlock problem (infinite waiting)
                        - May lead to starvation(long waiting)

                - Two phase locking protocol (2 PL)

                    - extension of shared exclusive protocol
                    - two phases are
                        - growing phase
                            - only acquire locks, do not release.
                            - if any lock is released, then shrinking phase starts.
                            - this happens seperately for each transaction

                        - shrinking phase
                            - only release locks, acquiring not allowed

                    - checkpoint/lockpoint
                        - the point at which shriking phase starts (after first unlocking)

                    - advantage
                        - It is serializable

                    disadvantage
                        - It can lead to irrecoverable schedule
                        - May also lead to deadlock problem (infinite waiting)
                        - May lead to starvation(long waiting)

                - Strict 2 PL

                    - follow the basic rules of basic 2 PL
                    - It says that the EXCLUSIVE LOCK on any item can't be given up unitll that item has not been commited

                    NOTE: It only says for exclusive lock only

                    -ex:

                        T1

                        X(A)
                        R(A)
                        W(A)
                        commit
                        U(A)


                    - advantages
                        - ensures serailizability and recoverability

                    - disadvantage
                        - deadlock and starvation

                - Rigorous 2 PL

                    - follows basic 2 PL
                    - Same as strict 2 PL but it follows for shared and exclusive lock both

                    - adv and disadv same as strict 2 PL

                - Conservative 2 PL

                    - Not a practical approach
                    - It requires the transaction to pre decalre the data items that it would require
                    - advantages
                        - all

        - timestanp protocol

            - whenever a transaction starts, it is provided with a unique number
            - these timestamps are provided in increasing order as the new transaction arrives
            - by this we can find the oldest and the newest transaction
            - represented by TS(T1)

            - RTS - read time stamp
            - WTS - write time stamp
            - RTS and WTS are calculated for a particular data item
            - RTS and WTS of a data item is equal to the TS of the transaction that reads/writes the data item at the last
            - ex:

                100           200           300
                T1            T2            T3

                R(A)
                                            R(A)

                              R(A)

                - so the RTS(A) = 200 bcz it has been read by T2 at last

            - Rules for TSP

                1. if a transaction T1 performs read operation R(A) on data item then

                    if WTS(A) > TS(T1)
                        then rollback T1
                    else
                        RTS(A) = max{ TS(T1), RTS(A)}

                2. if a transaction T1 performs write operation W(A) on data item then

                    if RTS(A) > TS(T1) ||  WTS(A) > TS(T1)
                        then rollback T1
                    else
                        WTS(A) = TS(T1)

            - ex and short trick
                - class 59 55:00

            - no deadlock occurs

        - tree based protocol
        - graph based protocol

# Indexing

    - It is a type of data structure
    - Searching time is reduced by using indexing
    - IO cost (moving data to-from ram and hard disk) is reduced
    - Index table structure
        - Key value | Reference or pointer value

    - Index table is stored in a block of hard disk
    - In indexing, only binary search is applied
    - Total searching time

        = [log2n] + 1
        - [log2n] for finding the block and 1 for finding the data in that block
        - [] for taking ceil value
        - n is the number of blocks in index table


    - types

        - dense indexing
            - used in unordered list
            - all the records of hard disk are kept in index table

        - sparse indexing

            - ordered list
            - only anchor record(first record of the block) is kept in the table

        NOTE:
                - in dense indexing,
                    Records in index table = no. of records in HD

                - in sparse indexing,
                    Records in index table = no. of blocks in HD


        - ex: numerical
                - class 60 49:00 (This is a bit confusing)
                - try gate smashers
                    - https://www.youtube.com/watch?v=P24LAhp-ap8
                    - https://www.youtube.com/watch?v=s_S_MpLoDEM

        - types of indexing in DBMS

            - Single level indexing

                - A single block of hard disk is used to create index table

                - primary
                    - ordered list with key (unique elements)
                    - ex: 1 2 3 4 5 6...

                    - sparse indexing
                    - total search time would be = [log2n] + 1

                - clustering
                    - ordered list with not key (duplicate elements)
                    - ex: 1 1 1 2 2 3 3

                    - unique values are kept in index table. We cannot define the no. of records in index table.
                    - if all the values are equal then only one entry would be made in index table.
                    - Maximum no. of records in index table = unique values in data
                    - sparse indexing
                    - total search time would be >= [log2n] + 1

                - secondary
                    - unordered list with key and non key
                    - dense indexing

                    1. unordered list with key value
                        - no. of records in index table = no. of records in HD
                        - total search time would be = [log2n] + 1

                    2. unordered list with non key value
                        - an intermediate layer is formed in this for each unique element whoch stores the block address for each address

                        - searching time >= log2n + 1

                NOTE: secondary indexing is also called non-clustered indexing.

            - Multiple level indexing

                - Multilevel indexing is used when the database and its indexes are too large to manage efficiently with single-level indexing.

                - B tree
                    - Balance tree
                    - A tree which has all the leaf nodes at the same level

                    - a B tree has the following
                        - Block pointer
                        - Key value
                        - Record pointer/Data pointer

                    - no. of block pointers = maximum no. of childs a node can have
                    - Key value count = maximum no. of childs a node can have - 1
                        OR
                    - Key value count = no. of block pointers - 1;

                    - Record pointer = maximum no. of childs a node can have - 1

                    - Binary search tree method is applied
                    - It is expanded in depth

                    - ex: Question is given like this

                        The order of B tree is 4.

                        sol. Here order means the maximum no. of childs a node can have.

                            so no. of block pointers = 4
                               Key value count = 4 - 1 = 3
                               Record pointer = 4 - 1 = 3

                    - the structure of parent and child is same.

                    - at root max child = no. of order
                    - at root min child = 2
                    - at intermediate node, child  = ceil(order/2)



                        -Q. given block size = 512 bytes, BP size = 5 bytes, key size = 10 bytes, RP size = 8 bytes. Find n.

                            put the value in the above formula and find n.

                            NOTE: if value comes in decimal, take floor value

                            ans = 23

                - B+ tree

                    - Faster method compared to B+ Tree
                    - the structure of leaf and non leaf node is different
                    - All the key-value are available at the leafnode due to which searching time is faster
                    - It increases breadthwise

                    - structure

                        - the root and intermediate nodes do not have record pointer. (only have BP and Key-value)
                        - the leaf node has key-value and RP and only one BP which is at the end of it.
                        - this BP points to another leaf node.

                    - BST is used

                    - IMP: numerical

                        formula:

                            - for non leaf
                                n.BP + (n-1).Key <= Block size

                                - no record pointers are there

                            - for leaf

                                nRP + nkey + Bp <= Block size

                                - only one block pointer is there

                            NOTE: if value comes in decimal, take floor value

# Recovery management

    - if any operation fails in transaction, then in order to maintain the atomicity, recovery is done

    1. Transaction failure

        - Logical error
            - overflow error
            - Not found error
            - bad inout

        - System error
            - Deadlock

    2. System crash

        - Bug in OS
        - S/w Bug
        - hardware malfunctioning

    3. Disk failure

# Recovery management techniques

    - undo/Rollback
    - Redo/commit
    - checkpoints


    - undo and redo are done through two methods

        - Log based recovery
            - deffered modification
            - Immediate modification

        - Shadow pagging


    1. Undo/Rollback

        - It means undone
        - If transaction fails then restore the old value

    2. Redo

        - It means Redone.
        - If transcation commits then store the updated value in database

# Log based recovery

    - log is a file which stores sequence of log records when a tracnsaction updates a data item(write operation)

    - log file is kept in stable memory which can't be deleted

    - structire of log file

        <Ti, Start>
        <Ti, Dataitem, old_val, new_val>
        <Ti, Commit>
            OR
        <Ti, Rollback>


    - Deferred modification

        - Late updation of database is there
        - Value is updated in the DB after commit or partial commit
        - only new value is kept in the log file

        - values are updated only after the transaction is commited
        - If transaction fails, then nothing is done (log file is discarded)
        - also called no undo/redo technique
        - no undo is done because not needed. We directly discard it.

    - Immediate modification

        - early modification
        - hand to hand modification  of the updated value in the database as the transaction writes the value
        - both new and updated values are kept in log file
        - also called undo/redo technique
        - undo means revert to old value

# Shadow pagging

    - in log based recovery, due to the generation of log file, a lot of disk space is used. To overcome that, shadow pagging is used.

    - two tables are used in this

        - current page table
        - shadow page table

    - initially current page table and shadow page table are identical
    - Transaction perform operations in current page table.
    - On the commit of transaction, the current page table is copied to shadow page table
    - shadow page table is st


# Checkpoint

    - It is point which shows that all the operations/transactions before checkpoint are committed and consistent.
    - all the files before the checkpoint are deleted

    - it contains undo and redo list

    - Undo List and Redo List

        During recovery, the system needs to ensure that all committed transactions are reflected in the database (redo) and that all uncommitted transactions are rolled back (undo). To achieve this, the system maintains undo and redo lists:

        - Undo List:

            Contains transactions that were active (in-progress) at the time of the crash and need to be rolled back.
            Ensures that the effects of uncommitted transactions are undone, maintaining data consistency.

        - Redo List:

            Contains transactions that committed before the crash but whose changes might not have been fully written to disk.
            Ensures that all committed transactions are reflected in the database, maintaining data durability.

    - ex: class 64 43:30

# Embedded SQL

    - SQL which does not changes at the run time
    - also called static SQL
    - It is used to connect high level language with the database

    - there are 4 steps in embedded sql writing

        - Database connection
        - Declaration of Embedded SQL ( starts with Begin, ends with End)
        - Execution of embedded SQL
        - Error handling

    - Taking value as input at runtime is not allowed

# Dynamic SQL

    - code can be changed at the runtime
    - It has procedures which is called stored procedure
    - It is used for flexible query

    - 4 steps are used

        - Take two variable A, B
        - set the first variable A as table name
        - set the second varaible B as Dynamic SQL
        - Execute the Dynamic SQL

    - ex:

        DECLARE

        @A varchar(100),
        @B varchar(100),

        @A = N'Student';
        @B = N'Select * from' @A;

        Exec sp_EXECUTE @B;

# File organization

    - File is a collection of relative information which is stroed in secondary storage

    - Types of file organization

        - sequential file org.

            - Pile FO
                - New records are placed in next available data block

            - Sorted FO
                - Records are stored in sorted order

                adv
                    - Data block maybe free
                    - Search time is very high. We cannot directly jump on a record

        - heap file org.

            - No sorting is used
            - all data blocks are used
            - new record is assigned to any data block which is available

            adv
                - less search time
                - Data block are utilised
                - used in smaller db

            disadv

                - not used in large db

        - hash file org.

            - hash value for a datablock is created

            - two types
                - static hashing

                    - problem = multiple records can have same memory location (due to mod)

                    - solution
                        - open hashing (IMP)
                            - also called liner probing
                            - if value is already there then look for next empty block

                        - closed hashing
                            - uses linked list to solve the problem

                - dynamic hashing
                    - data blocks grow as the data grow

        - B+ Tree file org.
        - clustered file org.
        - Sequential indexed file org.


- OLAP - Online Analytical processing 
- The blocking factor of a file is the no. of logical records in one physical record
- An assertion is a statement that ensures that certain conditions are always enforced in the database no matter what. 