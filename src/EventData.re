[@bs.val] external environment : string = "process.env.NODE_ENV";

let apiBaseUrl = switch environment {
  | "development" => "http://localhost:3000"
  | "production" => "https://associazioneyume.com"
  | _ => "http://localhost:3000"
};

let eventsUrl = {j|$apiBaseUrl/api/events|j};

type event = {
  id: int,
  title: string,
  description: string,
  location: string,
  image: string,
  starts_at: string,
  ends_at: string
};

type events = array(event);

module Decode = {
  let event = (json) : event =>
    Json.Decode.{
      id: json |> field("id", int),
      title: json |> field("title", string),
      description: json |> field("description", string),
      location: json |> field("location", string),
      image: json |> field("image", string),
      starts_at: json |> field("starts_at", string),
      ends_at: json |> field("ends_at", string)
    };
  let events = (json) : array(event) => Json.Decode.(json |> array(event));
};

let fetchEvents = (callback) =>
  Js.Promise.(
    Fetch.fetch(eventsUrl)
    |> then_(Fetch.Response.json)
    |> then_(
         (json) =>
           json
           |> Decode.events
           |> (
             (events) => {
               callback(events);
               resolve()
             }
           )
       )
    |> ignore
  );
