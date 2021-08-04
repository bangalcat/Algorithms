defmodule Boj.Boj9373Test do
  use ExUnit.Case

  alias Boj.Boj9373

  describe "test case" do
    test "case 1" do
      w = 10
      n = 2
      sensors = [{2, 0, 3}, {7, 12, 4}]

      assert Boj9373.solve(w, n, sensors) == 1.5
    end

    test "case 2" do
      w = 10
      n = 2
      sensors = [{2, 0, 3}, {7, 8, 4}]
      assert Boj9373.solve(w, n, sensors) == 1.216991
    end

    test "case 3" do
      w = 10
      n = 2
      sensors = [{2, 0, 3}, {7, 4, 4}]
      assert Boj9373.solve(w, n, sensors) == 0
    end
  end
end
