[%bs.raw {|require('foundation-sites/dist/css/foundation.css')|}];

[@bs.module "./registerServiceWorker"] external register_service_worker : unit => unit = "default";

register_service_worker();

ReactDOMRe.renderToElementWithId(<App />, "root");
