from lib.algo import nbonacciDegree, b
import pytest


class TestNBonacciDegree():

    def test_case_0(self):
        input = []
        assert -1 == nbonacciDegree(input)


    def test_case_1(self):
        input = [1, 2, 3]
        assert 2 == nbonacciDegree(input)


    def test_case_2(self):
        input = [0, 6, -2, 3, 7, 14, 22, 46, 89, 171, 328, 634, 1222, 2355]
        assert 4 == nbonacciDegree(input)


    def _test_b(self):

        assert 33 == b()


