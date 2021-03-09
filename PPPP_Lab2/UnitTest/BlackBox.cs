using NUnit.Framework;
using System;
namespace UnitTest
{
    public class Tests
    {
        //--------------------------two roots (only decision)
        
        //x==0 y==0
        [Test]
        public void Test1()
        {
            double a = 10, b = 0, c = 0, d = 10, e = 0, f = 0;
            string ans = PPPP_Lab2.Program.SolveEquation(a, b, c, d, e, f);
            string expectedAns = "2 0 0";
            Assert.AreEqual(ans, expectedAns);
        }
        //x==0 y!=0
        [Test]
        public void Test2()
        {
            double a = 10, b = 0, c = 0, d = 10, e = 1, f = 0;
            string ans = PPPP_Lab2.Program.SolveEquation(a, b, c, d, e, f);
            string expectedAns = "2 0,1 0";
            Assert.AreEqual(ans, expectedAns);
        }

        //x!=0 y==0
        [Test]
        public void Test3()
        {
            double a = 10, b = 0, c = 0, d = 10, e = 0, f = 1;
            string ans = PPPP_Lab2.Program.SolveEquation(a, b, c, d, e, f);
            string expectedAns = "2 0 0,1";
            Assert.AreEqual(ans, expectedAns);
        }

        //x!=0 y!=0
        [Test]
        public void Test4()
        {
            double a = 10, b = 0, c = 0, d = 10, e = 1, f = 1;
            string ans = PPPP_Lab2.Program.SolveEquation(a, b, c, d, e, f);
            string expectedAns = "2 0,1 0,1";
            Assert.AreEqual(ans, expectedAns);
        }

        //--------------------------------------infinitive roots
        //y=y0
        [Test]
        public void Test5()
        {
            double a = 0, b = 2, c = 0, d = 0, e = 2, f = 0;
            string ans = PPPP_Lab2.Program.SolveEquation(a, b, c, d, e, f);
            string expectedAns = "4 1";
            Assert.AreEqual(ans, expectedAns);
        }

        [Test]
        public void Test6()
        {
            double a = 0, b = 0, c = 0, d = 2, e = 0, f = 2;
            string ans = PPPP_Lab2.Program.SolveEquation(a, b, c, d, e, f);
            string expectedAns = "4 1";
            Assert.AreEqual(ans, expectedAns);
        }

        [Test]
        public void Test7()
        {
            double a = 0, b = 2, c = 0, d = 2, e = 2, f = 2;
            string ans = PPPP_Lab2.Program.SolveEquation(a, b, c, d, e, f);
            string expectedAns = "4 1";
            Assert.AreEqual(ans, expectedAns);
        }

        //------------------------------------------infinitive roots
        //x=x0
        [Test]
        public void Test8()
        {
            double a = 2, b = 0, c = 0, d = 0, e = 2, f = 0;
            string ans = PPPP_Lab2.Program.SolveEquation(a, b, c, d, e, f);
            string expectedAns = "3 1";
            Assert.AreEqual(ans, expectedAns);
        }

        [Test]
        public void Test9()
        {
            double a = 0, b = 0, c = 2, d = 0, e = 0, f = 2;
            string ans = PPPP_Lab2.Program.SolveEquation(a, b, c, d, e, f);
            string expectedAns = "3 1";
            Assert.AreEqual(ans, expectedAns);
        }

        [Test]
        public void Test10()
        {
            double a = 2, b = 0, c = 2, d =0, e = 2, f = 2;
            string ans = PPPP_Lab2.Program.SolveEquation(a, b, c, d, e, f);
            string expectedAns = "3 1";
            Assert.AreEqual(ans, expectedAns);
        }

        //--------------------------------infinitive roots x - all y - all
        [Test]
        public void Test11()
        {
            double a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
            string ans = PPPP_Lab2.Program.SolveEquation(a, b, c, d, e, f);
            string expectedAns = "5";
            Assert.AreEqual(ans, expectedAns);
        }

        //-----------------------------------no roots
        [Test]
        public void Test12()
        {
            double a = 5, b = 2, c = 15, d = 6, e = 2, f = 0;
            string ans = PPPP_Lab2.Program.SolveEquation(a, b, c, d, e, f);
            string expectedAns = "0";
            Assert.AreEqual(ans, expectedAns);
        }

        [Test]
        public void Test13()
        {
            double a = 3.4, b = -5.1, c = 10.2, d = -15.3, e = 11.9, f = 20.4;
            string ans = PPPP_Lab2.Program.SolveEquation(a, b, c, d, e, f);
            string expectedAns = "0";
            Assert.AreEqual(ans, expectedAns);
        }
    }
}