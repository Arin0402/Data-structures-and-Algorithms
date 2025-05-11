# Visitor design pattern

    - https://www.youtube.com/watch?v=pDsz-AuFO0g&ab_channel=Concept%26%26Coding-byShrayansh

    - The Visitor Pattern lets you add new operations to existing classes without changing them, by using a separate Visitor class. 

    - It breaks the open closed principle for classes like if we have to add a new object in visitor interface, in the above case.. if we add a new kind of room then we have to edit the interface and classes
    
    - If you have many types and visitors, the code becomes hard to manage and scales poorly.

    - We should be using this when the concrete classes are stable and operations keep on adding and reducing