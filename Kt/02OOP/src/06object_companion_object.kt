object X {
    var x = 0
}

data class StudentB(
    val id: Int, val firstName: String, val
    lastName: String
) {
    var fullName = "$lastName, $firstName"
}

object StudentRegistry {
    val allStudents = mutableListOf<StudentB>()
    fun addStudent(student: StudentB) {
        allStudents.add(student)
    }

    fun removeStudent(student: StudentB) {
        allStudents.remove(student)
    }

    fun listAllStudents() {
        allStudents.forEach {
            println(it.fullName)
        }
    }
}

object JsonKeys {
    const val JSON_KEY_ID = "id"
    const val JSON_KEY_FIRSTNAME = "first_name"
    const val JSON_KEY_LASTNAME = "last_name"
}

class Scientist private constructor(
    val id: Int,
    val firstName: String,
    val lastName: String
) {
    companion object {
        var currentId = 0
        fun newScientist(firstName: String, lastName: String):
                Scientist {
            currentId += 1
            return Scientist(currentId, firstName, lastName)
        }
    }

    var fullName = "$firstName $lastName"
}

object ScientistRepository {
    val allScientists = mutableListOf<Scientist>()
    fun addScientist(student: Scientist) {
        allScientists.add(student)
    }

    fun removeScientist(student: Scientist) {
        allScientists.remove(student)
    }

    fun listAllScientists() {
        allScientists.forEach {
            println("${it.id}: ${it.fullName}")
        }
    }
}

fun main() {
    println(X.x)
    val marie = StudentB(1, "Marie", "Curie")
    val albert = StudentB(2, "Albert", "Einstein")
    val richard = StudentB(3, "Richard", "Feynman")

    StudentRegistry.addStudent(marie)
    StudentRegistry.addStudent(albert)
    StudentRegistry.addStudent(richard)
    StudentRegistry.listAllStudents()
// > Curie, Marie
// > Einstein, Albert
// > Feynman, Richard

    println(JsonKeys.JSON_KEY_ID)

    val emmy = Scientist.newScientist("Emmy", "Noether")
    val isaac = Scientist.newScientist("Isaac", "Newton")
    val nick = Scientist.newScientist("Nikola", "Tesla")
    ScientistRepository.addScientist(emmy)
    ScientistRepository.addScientist(isaac)
    ScientistRepository.addScientist(nick)
    ScientistRepository.listAllScientists()
// 1: Emmy Noether
// 2: Isaac Newton
// 3: Nikola Tesla
}