[@bs.module "./registerServiceWorker"] external register_service_worker : unit => unit = "default";

register_service_worker();

let renderForRoute = (route) =>
  ReactDOMRe.renderToElementWithId(<App route />, "root");

let router =
  DirectorRe.makeRouter({
    "/": () => renderForRoute(Routing.Home)
  });

DirectorRe.init(router, "/");
