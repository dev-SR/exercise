class Student2 {
    val school: String = "Merit Model"
    var age: Int = 5

    val isTeenager: Boolean
        get() {
            return age > 12
        }

    var name: String? = null
        get() = field ?: "Unknown"
        set(value) {
            if (value != null) field = value
        }
}

fun main() {
    val student: Student2 = Student2()
    println("1. Student is Teenager: ${student.isTeenager}")
    student.age = 14
    println("2. Student is Teenager: ${student.isTeenager}")
    println("3. Student name is: ${student.name}")
    student.name = "Soikat"
    println("4. Student name is: ${student.name}")
}