import kotlinx.coroutines.*
import kotlinx.coroutines.flow.*
import java.lang.IndexOutOfBoundsException

suspend fun getValues() = flow {
    val values = listOf(1, 2, 3)
    for (value in values) {
        delay(1000)
        emit(value)
    }

}
//suspend fun  getValues() = flowOf(1, 2, 3)
//suspend fun  getValues() = listOf(1, 2, 3).asFlow()

//suspend fun getValues(): List<Int> {
//    delay(1000)
//    return listOf(1, 2, 3)
//}
//fun processValues() {
//    runBlocking {
//        println("Processing.....")
//        val values = getValues()
//        for (value in values) {
//            println(value)
//        }
//    }
//    println("Done!")
//}

fun main() = runBlocking {
    (1..10).asFlow()
        .flowOn(Dispatchers.IO)
        .collect {
            println(it)
        }


}

