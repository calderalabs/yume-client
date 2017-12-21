variable "domain" {
  default = "associazioneyume.com"
}

variable "bucket" {
  default = "yume-client-production"
}

variable "regions" {
  type = "map"

  default = {
    "eu" = "eu-west-1"
    "us" = "us-east-1"
  }
}
