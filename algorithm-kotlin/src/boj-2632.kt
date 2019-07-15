import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val goal = readLine().toInt()
    val (a_cnt, b_cnt) = readLine().split(' ').map { it.toInt() }
    val alist = IntArray(a_cnt)
    val blist = IntArray(b_cnt)
    (0 until a_cnt).forEach { i ->
        alist[i] = readLine().toInt()
    }
    for(i in 0 until b_cnt)
        blist[i]  = readLine().toInt()

    var ret = 0

    fun pick(remain : Int, a_prev : Int, b_prev : Int, a_ct : Int, b_ct : Int) {
        if(remain == 0) {
            ret++
            return
        }
        if(a_ct < a_cnt) {
            if(a_prev == -1) {
//                for(i in 0 until a_cnt) {
//                    if(remain < alist[i])
//                        break
//                    pick(remain - alist[i], i, b_prev, a_ct+1, b_ct)
//                }
            }
            else {
                if (a_prev == a_cnt - 1 && remain > alist[0])
                    pick(remain - alist[0], 0, b_prev, a_ct + 1, b_ct)
                else if (remain > alist[a_prev + 1])
                    pick(remain - alist[a_prev + 1], a_prev + 1, b_prev, a_ct + 1, b_ct)
            }
        }
        if(b_ct < b_cnt) {
            if(b_prev == -1) {
                for(i in 0 until b_cnt) {
                    if(remain < blist[i])
                        break
                    pick(remain - blist[i], a_prev, b_prev, a_ct, b_ct+1)
                }
            }
            else {
                if (b_prev == b_cnt - 1 && remain > blist[0])
                    pick(remain - blist[0], a_prev, 0, a_ct, b_ct + 1)
                else if (remain > blist[b_prev + 1])
                    pick(remain - blist[b_prev + 1], a_prev, 0, a_ct, b_ct + 1)
            }
        }
    }
}
