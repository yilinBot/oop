#pragma once

class Noveny
{
    protected:
        int _eresIdo;
    public:
        Noveny(int i) : _eresIdo(i) {}
        getEresIdo() const { return _eresIdo; }
        virtual ~Noveny() {}
};


class Haszon : public Noveny
{
    public:
        Haszon(int i) : Noveny(i) {}
};

class Virag : public Noveny
{
    public:
        Virag(int i) : Noveny(i) {}
};

// A konkréz növényfajok osztályai legyenek egykék

class Burgonya : public Haszon
{
    public:
        static Burgonya* peldany();
    private:
        Burgonya() : Haszon(5) {}
        static Burgonya* _peldany;
};

class Borso : public Haszon
{
    public:
        static Borso* peldany();
    private:
        Borso() : Haszon(3) {}
        static Borso* _peldany;
};

class Hagyma : public Haszon
{
    public:
        static Hagyma* peldany();
    private:
        Hagyma() : Haszon(4) {}
        static Hagyma* _peldany;
};

class Rozsa : public Virag
{
    public:
        static Rozsa* peldany();
    private:
        Rozsa() : Virag(8) {}
        static Rozsa* _peldany;
};

class Szegfu : public Virag
{
    public:
        static Szegfu* peldany();
    private:
        Szegfu() : Virag(10) {}
        static Szegfu* _peldany;
};

class Tulipan : public Virag
{
    public:
        static Tulipan* peldany();
    private:
        Tulipan() : Virag(7) {}
        static Tulipan* _peldany;
};
