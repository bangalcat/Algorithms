defmodule DynamicProgramming do
  @moduledoc false

  def test(n, nums) do
    {:ok, n} = IO.gets("") |> Integer.parse()

    Enum.map(1..n, fn _ ->
      {:ok, two_num} = IO.gets("")

      two_num
      |> String.split()
    end)
  end
end
