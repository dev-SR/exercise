data class StudentA(val name: String, var section: String) {
    var age: Int = 8
}

fun main() {
    val student = StudentA("Jhon", "A")
    student.age = 10
    val student1 = StudentA("Jhon", "A")
    println("1. equal(): ${student.equals(student1)}")
    println("2. toString(): $student")
    val student2 = student.copy(name = "Mark")
    println("3. copy(): $student2")

    //destructing
    val (name, section) = student
    println("4. destructuring: $name is in section $section")
}
//1. equal(): true
//2. toString(): StudentA(name=Jhon, section=A)
//3. copy(): StudentA(name=Mark, section=A)
//4. destructuring: Jhon is in section A