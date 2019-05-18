function getParams() {

    const params = {};
    const arr = location.search.split("&");

    for (const s of arr) {
        const [key, value] = s.split("=");
        params[key.replace("?", "")] = value;
    }

    return params;

}

// A google search for 'google' would return something like this this:
// {
//     "source": "hp",
//     "ei": "92HgXP0NhfirAZC-oaAL",
//     "q": "google",
//     "oq": "google",
//     "gs_l": "psy-ab.12...0.0..2212...0.0..0.0.0.......0......gws-wiz."
// }
