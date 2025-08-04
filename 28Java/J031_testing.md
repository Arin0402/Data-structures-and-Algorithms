#### What is unit testing?

**Unit testing** is a software testing technique where **individual components or functions** of a program (called "units") are tested **in isolation** to ensure they work as expected.

---

### ✅ **Interview-Ready Definition:**

> **Unit testing** is the process of testing the **smallest testable parts** of an application — typically individual methods or classes — **independently** from the rest of the system to verify that they behave correctly.

---

### 🔧 **Key Characteristics:**

- **Automated**: Typically written and run using testing frameworks like **JUnit (Java)**, **pytest (Python)**, or **Mocha (JavaScript)**

---

### ✅ **Example (Java - using JUnit)**

Let’s say we have a class:

```java
public class Calculator {
    public int add(int a, int b) {
        return a + b;
    }
}
```

**Unit test:**

```java
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class CalculatorTest {
    @Test
    void testAdd() {
        Calculator calc = new Calculator();
        assertEquals(5, calc.add(2, 3));
    }
}
```

---

### 🎯 **Why Unit Testing is Important:**

- **Catches bugs early**
- **Makes code easier to refactor**
- **Improves code reliability and confidence**
- **Enables Test-Driven Development (TDD)**
- **Documents expected behavior**

---

### ❗ Not to be Confused With:

| Testing Type        | Scope                          |
| ------------------- | ------------------------------ |
| Unit Testing        | Individual methods/functions   |
| Integration Testing | Combined components or modules |
| System Testing      | Full end-to-end system test    |
| Acceptance Testing  | User/business-level testing    |

---

Let me know if you want help writing unit tests for your own code or setting up a testing framework.

### how is unit testing done in spring boot ?

In **Spring Boot**, unit testing is typically done using **JUnit** (often JUnit 5), along with **Mockito** for mocking dependencies. Spring Boot also provides testing utilities like `@SpringBootTest`, but that's more suited for integration testing. For **true unit testing**, you isolate and test individual components (like services or controllers) without loading the full Spring context.

---

### ✅ Interview-Ready Summary:

> In Spring Boot, **unit testing** is done using **JUnit and Mockito** by testing individual components like **services or controllers** in **isolation**, mocking any dependencies using `@Mock` or `@MockBean`.

---

### 🧪 Typical Setup for Unit Testing in Spring Boot:

#### 1. **Add dependencies (Maven)**

```xml
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-test</artifactId>
    <scope>test</scope>
</dependency>
```

This brings in:

- JUnit
- Mockito
- Hamcrest (assertions)
- Spring Test

---

### 📘 Example: Unit Testing a Service

Suppose you have this service:

```java
@Service
public class OrderService {
    private final PaymentService paymentService;

    public OrderService(PaymentService paymentService) {
        this.paymentService = paymentService;
    }

    public boolean placeOrder(int amount) {
        return paymentService.charge(amount);
    }
}
```

### ✅ Unit Test for `OrderService`:

```java
@ExtendWith(MockitoExtension.class)
class OrderServiceTest {

    @Mock
    PaymentService paymentService;

    @InjectMocks
    OrderService orderService;

    @Test
    void testPlaceOrderSuccess() {
        when(paymentService.charge(100)).thenReturn(true);

        boolean result = orderService.placeOrder(100);

        assertTrue(result);
        verify(paymentService).charge(100);
    }
}
```

---

### 📌 Key Annotations:

| Annotation         | Purpose                              |
| ------------------ | ------------------------------------ |
| `@Test`            | Marks the test method (JUnit)        |
| `@Mock`            | Creates a mock of a dependency       |
| `@InjectMocks`     | Injects mocks into the tested class  |
| `@ExtendWith(...)` | Enables Mockito or Spring extensions |

---

### 🚫 Avoid in Unit Tests:

- `@SpringBootTest` → Loads full application context (use for integration tests).
- Real DB/API calls → Use mocks/stubs.

---

### ✅ Best Practices:

- Test **one class/method** per unit test class.
- Use **descriptive method names** (`testPlaceOrder_WhenPaymentSucceeds_ReturnsTrue`)
- Keep tests **fast and isolated**.
- Use **mock behavior (`when().thenReturn()`)** to control external behavior.

---

### Explain the above test case

Great question — let’s break this down step by step so it’s crystal clear what’s happening in your unit test:

---

### 🔍 Code Summary

You're **unit testing** the `OrderService` class in **isolation**, by **mocking** its dependency `PaymentService` using **Mockito**.

---

### 📦 Dependencies Used

- **JUnit 5** for writing and running tests.
- **Mockito** for creating and injecting mock objects.

---

### 🧩 What Each Annotation Does

```java
@ExtendWith(MockitoExtension.class)
```

- This tells JUnit to use **Mockito's test runner**.
- It enables annotations like `@Mock` and `@InjectMocks`.

---

```java
@Mock
PaymentService paymentService;
```

- This creates a **mock object** of `PaymentService`.
- It's a fake version that you control manually (via `when(...)`).

---

```java
@InjectMocks
OrderService orderService;
```

- This **injects** the mock `paymentService` into the real `OrderService` instance.
- You're not mocking `OrderService` — you’re testing the **real logic**, but its dependencies are mocked.

---

### 🧪 Test Method Explained

```java
@Test
void testPlaceOrderSuccess() {
```

- Marks this method as a **test**.

---

```java
when(paymentService.charge(100)).thenReturn(true);
```

- This **defines mock behavior**.
- When `paymentService.charge(100)` is called, it should return `true`.

---

```java
boolean result = orderService.placeOrder(100);
```

- This is the **actual method call** you're testing.
- Under the hood, `orderService` will call `paymentService.charge(100)`, which is mocked to return `true`.

---

```java
assertTrue(result);
```

- Verifies that the **result** is `true`, as expected.

---

```java
verify(paymentService).charge(100);
```

- Ensures that `paymentService.charge(100)` was actually **called**.
- Helps confirm that your method is using its dependencies correctly.

---

### 🎯 Purpose of the Test

You're verifying that:

- `OrderService.placeOrder(100)` behaves correctly when `paymentService.charge(100)` returns true.
- The `charge()` method was called with the correct input.

---

### ✅ Why This is a Good Unit Test

- It's **isolated**: doesn't rely on real implementations of `PaymentService`.
- It's **fast**: no I/O or context loading.
- It's **repeatable**: always behaves the same since you control the mock.

---

Let me know if you'd like to see a failure case or test for exceptions!
