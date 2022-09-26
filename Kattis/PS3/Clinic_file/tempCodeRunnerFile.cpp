auto cmp = [K,ct](const Patient &a, const Patient &b) {
        if (a.get_sv(ct,K) == b.get_sv(ct,K)) {
            return a.get_name() > b.get_name();
        }
        return a.get_sv(ct,K) < b.get_sv(ct,K);
        };