import java.io.BufferedReader
import java.io.FileReader
import java.io.InputStreamReader
import java.util.*
import java.util.Collections.swap
import kotlin.Comparator

// 백터 매칭

data class Point(val x : Int, val y : Int) : Comparable<Point> {
    override fun compareTo(other: Point): Int {
        return when {
            x == other.x -> when {
                y == other.y -> 0
                y > other.y -> 1
                else -> -1
            }
            x > other.x -> 1
            else -> -1
        }
    }
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    //fun main() = with(BufferedReader(FileReader("src/input.in"))){
    val T = readLine().toInt()
    repeat(T) {
        val N = readLine().toInt()
        val plist = mutableListOf<Point>()
        repeat(N) {
            val (x,y) = readLine().split(' ').map { it.toInt() }
            plist += Point(x, y)
        }
        val permArray = IntArray(N){i -> if(i<N/2) 0 else 1}.toList()

        do{
            
        }while(nextPermutation(permArray))

    }
}

fun <T:Comparable<T>>nextPermutation(arr : List<T>) : Boolean{
    //i는 증가하지 않은 가장 긴 접미사 인덱스
    var i = arr.size - 1
    while(i > 0 && arr[i-1] >= arr[i]) {
        i--
    }
    if(i <= 0)
        return false
    // arr[i-1] 요소를 피벗으로 정합
    // 위의 피벗과 스왑할 위의 피벗을 초과한 가장 큰 오른쪽 요소를 찾음
    var j = arr.size - 1
    while(arr[j] <= arr[i-1])
        j--

    //assertion j >= i

    swap(arr, i-1, j)

    //위의 과정이 일어나더라도 사전순으로 되지 않음.
    //접미사 인덱스를 활용해 반대로 만들어준다
    j = arr.size - 1
    while(i < j) {
        swap(arr, i, j)
        i++
        j--
    }
    return true
}
